#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=1e4+7;

ll dp[N];
struct node{
	ll w,s,v;
}a[1007];

bool cmp(node a,node b){
	return a.s-b.w>b.s-a.w;
}

int main(){
	int n=input();
	for(int i=1;i<=n;i++){
		a[i].w=input(),a[i].s=input(),a[i].v=input();
	}

	sort(a+1,a+1+n,cmp);

	for(int i=1;i<=n;i++){
		for(int j=a[i].w;j<=10000;j++)
			dp[min(j-a[i].w,a[i].s)]=max(dp[min(j-a[i].w,a[i].s)],dp[j]+a[i].v);
		dp[a[i].s]=max(dp[a[i].s],a[i].v);
	}
	ll Ans=0;
	for(int i=0;i<=10000;i++) Ans=max(Ans,dp[i]);
	printf("%lld\n",Ans);
}