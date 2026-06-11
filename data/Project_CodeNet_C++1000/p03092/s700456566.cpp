#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
using namespace std;
const int N=5005;
int n,A,B,a[N];
int p[N];
ll f[2][N];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	For(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	For(i,1,n) For(j,0,n){
		int co=(j==p[i]?0:(j<p[i]?B:A));
		f[i&1][j]=min(j==0?1ll<<60:f[i&1][j-1],f[(i&1)^1][j]+co);
	}
	printf("%lld\n",f[n&1][n]);
}