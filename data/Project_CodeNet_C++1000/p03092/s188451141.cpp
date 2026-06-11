#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=5050;
const ll INF=1e16;
int n,A,B,a[N];
ll ans,f[N][N];
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&A,&B);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,0,n)FOR(j,0,n) f[i][j]=INF;
	f[0][0]=0;ans=INF;
	FOR(i,1,n){
		FOR(j,0,i-1){
			if(a[j]<a[i]){
				f[i][j]=min(f[i][j],f[i-1][j]+A);
				f[i][i]=min(f[i][i],f[i-1][j]);
			}
			else
				f[i][j]=min(f[i][j],f[i-1][j]+B);
		}
	}
	FOR(i,1,n) ans=min(ans,f[n][i]);
	cout<<ans<<'\n';
}