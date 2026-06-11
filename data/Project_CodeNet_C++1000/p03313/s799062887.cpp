#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N=18,M=1<<18;
int memo[M][N][3],n,m,arr[M],ans[M];
int solve(int v,int idx,int cnt){
	if(idx<0)return ( cnt == 1 ? arr[v]:-2e9);
	if( !(v&(1<<idx)) )return solve(v,idx-1,cnt);
	int &ret=memo[v][idx][cnt];
	if(~ret)return ret;
	ret=solve(v,idx-1,cnt);
	if(cnt == 1)ret = max(ret, solve(v^(1<<idx),idx-1,cnt));
	if(cnt == 2)ret =max(ret, solve(v,idx-1,1) + solve(v^(1<<idx),idx-1,1));

	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("i.txt","r",stdin);
#endif
	sc(n);
	m=(1<<n);
	lop(i,m)sc(arr[i]);
	memset(memo,-1,sizeof memo);
	for(int i=1;i<m;i++){
		ans[i]=max(ans[i-1],solve(i,n-1,2));
		printf("%d\n",ans[i]);
	}

}
