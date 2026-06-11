#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int n;
int a[N];
map<int,int> st;
bool test(int cnt){
	st.clear();
	for(int i=1;i<=n;i++){
		if(a[i]<=a[i-1]){
			int j=a[i];
			while(++st[j]==cnt){
				j--;
				if(j==0||cnt==1){
					return false;
				}
			}
			while(!st.empty()&&(--st.end())->first>j){
				st.erase(--st.end());
			}
		}
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[0]=0;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(test(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",l);
}