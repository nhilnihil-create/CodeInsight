#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define ll long long
#define db double
#define pb push_back
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,H,W,f[N],nowx,nowy,ans;
std::map<int,int>mp[N];
struct point{int x,y;}A[N];
std::vector<int>S[N];
int main()
{
	scanf("%d%d%d",&H,&W,&n),nowx=nowy=1,ans=H;
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i].x,&A[i].y),mp[A[i].x][A[i].y]=1,S[A[i].y].pb(A[i].x);
	if(!n) return !printf("%d\n",H);
	f[1]=1;
	for(int i=1;i<=H;i++)
	{
		if(mp[nowx+1][nowy]) break;
		nowx++;
		if(nowy<W&&!mp[nowx][nowy+1]) nowy++,f[nowy]=nowx;
		// dbg1(nowx),dbg2(nowy);
	}
	for(int i=1;i<=nowy;i++) S[i].pb(H+1),std::sort(S[i].begin(),S[i].end());
	for(int i=1,res;i<=nowy;i++)
	{
		res=std::lower_bound(S[i].begin(),S[i].end(),f[i])-S[i].begin();
		ans=min(ans,S[i][res]-1);
		// dbg1(i),dbg1(f[i]),dbg2(res);
	}
	printf("%d\n",ans);
	return 0;
}