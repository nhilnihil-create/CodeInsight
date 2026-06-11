#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=20,M=1<<N;

ll st[M],dp[M];
int a[N][N];

int main(){
	int n=input();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=input();

	for(int t=0;t<(1<<n);t++){
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				if((t&(1<<i))&&(t&(1<<j)))
					st[t]+=a[i][j];
			}
	}

	for(int t=0;t<(1<<n);t++){
		for(int t2=t;t2>0;t2=(t2-1)&t){
			ll tmp=dp[t-t2]+st[t2];
			dp[t]=max(dp[t],tmp);
		}
	}

	printf("%lld\n",dp[(1<<n)-1]);
}