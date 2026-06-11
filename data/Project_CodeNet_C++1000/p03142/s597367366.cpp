///supercalifragilisticexpialidocious.
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <complex>
using namespace std;
#define f first
#define s second
#define endl '\n'
#define PB pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
typedef pair<int , pair<int , int> > piii;
const int MAXN = 1e5 + 10;
int n , m , a , b , d[MAXN] , par[MAXN];
vector<int> adj[MAXN] , vec[MAXN];
void dfs(int u)
{
	for(auto v : adj[u])
		d[v] --;
	for(auto v : adj[u])
		if(!d[v])
			vec[u].pb(v);
	for(auto v : vec[u])
		par[v] = u , dfs(v);
	return;
}
void input()
{
	cin >> n >> m;
	for(int i = 0 ; i < n + m - 1 ; i ++)
		cin >> a >> b , a -- , b -- , adj[a].pb(b) , d[b] ++;
	return;
}
int32_t main()
{
	input();
	for(int i = 0 ; i < n ; i ++)
		if(!d[i])
		{
			par[i] = -1 , dfs(i) ; break;
		}
	for(int i = 0 ; i < n ; i ++)
		cout << par[i] + 1 << endl;
	return 0;
}
