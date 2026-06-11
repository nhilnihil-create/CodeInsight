#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define mst(a) memset(a,0,sizeof a)
int a[N],n;
ll ans; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int l=1,r=1,sum=0;l<=n;){
		while(r<=n&&(sum^a[r])==sum+a[r]) sum^=a[r++];
		ans+=r-l,sum^=a[l++];
	}
	printf("%lld\n",ans);
	return 0;
} 