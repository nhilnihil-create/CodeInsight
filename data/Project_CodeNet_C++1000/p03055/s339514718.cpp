#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int INF = 1e18;
const int M = 1e9 + 7;
//__int128

const int maxn = 3e5;
std::vector<int> G[maxn];
int len = 1;
int d[maxn];
int bfs(int x) {
	queue<int> q;
	q.push(x);
	memset(d, 0, sizeof(d));
	int res = 0;
	d[x] = 1;
	bitset<maxn> vis;
	vis[x] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto i : G[u]) {
			if(!vis[i]) {
				q.push(i);
				vis[i] = 1;
				d[i] = d[u] + 1;
				if(d[i] > len) {
					res = i;
					len = d[i];
				}
			}
		}
	}
	return res;
}

signed main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
    	int u, v;
    	cin >> u >> v;
    	G[u].eb(v);
    	G[v].eb(u);
    }
    int x = bfs(1);
    bfs(x);
    bitset<maxn> sg;
    sg[1] = 1;
    for(int i = 3; i <= len; ++i) {
    	sg[i] = !(sg[i - 1] && sg[i - 2]);
    }
    if(sg[len]) {
    	cout << "First" << endl;
    } else {
    	cout << "Second" << endl;
    }
    return 0;
}