#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=100010;
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	int ans,min_diff=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(abs((a[n]+1)/2-a[i])<min_diff){
			min_diff=abs((a[n]+1)/2-a[i]);
			ans=a[i];
		}
	}
	printf("%d %d\n",a[n],ans);
	return 0;
}