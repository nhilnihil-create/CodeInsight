//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem in C++
// MAIN IDEA   : combinatorics NCR
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define rw freopen("graphs_as_a_service.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define rep(i,a) lp(i,0,a-1)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace __gnu_pbds;
using namespace std;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = 1e5 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
vii v[N];
int st[N], fi[N], t, e[N], vis[N], cur = 0;
void dfs(int node) {
	st[node] = (++t);
	for (auto u : v[node]) {
		int ch = u.F;
		if (!st[ch])
			dfs(ch);
		else if (!fi[ch]) {
			puts("No");
			exit(0);
		}
	}
	fi[node] = (++t);
}
bool in[N];
inline void dij(int node) {
	priority_queue<pii, vii, greater<pii>> pq;
	e[node] = 0;
	vis[node] = cur;
	pq.push( { 0, node });
	while (!pq.empty()) {
		pii a = pq.top();
		pq.pop();
		for (auto u : v[a.S]) {
			if (vis[u.F] && vis[u.F] < cur)
				continue;
			if (e[u.F] > a.F + u.S && e[u.F] == INF) {
				e[u.F] = a.F + u.S;
				vis[u.F] = cur;
				pq.push( { e[u.F], u.F });
			} else if (e[u.F] != a.F + u.S && e[u.F] != INF) {
				puts("No");
				exit(0);
			}
		}
	}
}
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	int n, m;
	cin >> n >> m;
	lp(i,1,m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		in[b] = true;
		v[a].pb( { b, c });
	}
	lp(i,1,n)
	{
		if (!st[i])
			dfs(i);
	}
	lp(i,1,n)
		e[i] = INF;
	lp(i,1,n)
	{
		cur++;
		if (!in[i] && !vis[i])
			dij(i);
	}
	f("Yes");
	return 0;
}
