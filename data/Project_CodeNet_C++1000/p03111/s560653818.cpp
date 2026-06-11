#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int n,A,B,C;
const int inf=1e9;
vector<int> l;
int dfs(int cur,int a,int b,int c)
{
	if(cur==n)
	{	if(min({a,b,c})>0)
		return(abs(C-c)+abs(B-b)+abs(A-a)-30);
		else return inf;
	}
	int r1=dfs(cur+1,a,b,c);
	int r2=dfs(cur+1,a+l[cur],b,c)+10;
	int r3=dfs(cur+1,a,b+l[cur],c)+10;
	int r4=dfs(cur+1,a,b,c+l[cur])+10;
	return min({r1,r2,r3,r4});
}
int32_t main()
{
	n=in();A=in();B=in();C=in();
	l=vector<int>(n);
	trav(i,l){i=in();}
	cout<<dfs(0,0,0,0);
	
}