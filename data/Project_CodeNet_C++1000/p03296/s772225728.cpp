#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt,k=0;
vector<int> v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i-1]);
		if(i==1){
			cnt=1;
			continue;
		}
		if(a[i-1]==a[i-2]){
			++cnt;
		}else{
			v.push_back(cnt);
			cnt=1;
		}
	}
	v.push_back(cnt);
	for(int i=0;i<v.size();i++){
		k+=(v[i]/2);
	}
	printf("%d",k);
}