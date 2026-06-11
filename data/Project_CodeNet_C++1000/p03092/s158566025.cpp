#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
const long long N=(5050),M=(250025),LEN=(50);
const long long Mod=(323232323);
const long double EPS=(1e-7);
const long long MAX=(1e18);
///////////////////////////////////////////////
int n,a[N];
long long ans=MAX,A,B,f[N][N];
int main(){
	//freopen("problem.in","r",stdin);
	//freopen("problem.out","w",stdout);
	scanf("%d%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=MAX;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i]>j){
				f[i][j]=min(f[i][j],f[i-1][j]+A);
				f[i][a[i]]=min(f[i][a[i]],f[i-1][j]);
			}
			if(a[i]<j) f[i][j]=min(f[i][j],f[i-1][j]+B);
		}
	}
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}
/*
3 1 6 2
3 3 6 6
4 5
4 5
*/