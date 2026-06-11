#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define left(x) x * 2
#define right(x) x * 2 + 1

#define eb emplace_back

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define ml " "
#define nl endl

#define lb lower_bound
#define ub upper_bound

#define fo(i, a, b) for (int i = a; i <= b; ++ i)
#define foo(i, a, b) for (int i = a; i >= b; -- i)

#define srt(a, n) sort(a, a + n)

const int N = 4e6 + 10;
const int sz = 1 << 17;
const int MOD = 1e9 - 7;
const int INF = 4e5 + 7;

int d[N];

vector <int> g[N];

bool u[N], u2[N];

queue <int> q;

int n, d2[N];

int bfs(int x) {
	q.push(x);
    d[x] = 0;
    u[x] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)g[v].size(); ++ i)
        {
            int to = g[v][i];
            if (!u[to])
            {
                u[to] = 1;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    int mx = 0;
    int pos = 0;
    for (int i = 1; i <= n; ++ i) {
   		if (mx < d[i]) {
   			mx = d[i];
   			pos = i;
   		}
    }
   	return pos;
}

int bfs1(int x) {
	q.push(x);
    d2[x] = 0;
    u2[x] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)g[v].size(); ++ i)
        {
            int to = g[v][i];
            if (!u2[to])
            {
                u2[to] = 1;
                q.push(to);
                d2[to] = d2[v] + 1;
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++ i)
    	mx = max(d2[i], mx);
    return mx;
}

main (){
	clog << "Ready\n";
	
	cin >> n;
	
	for (int i = 1; i < n; ++ i) {
		int x, y;
		cin >> x >> y;
		g[x].eb(y);
		g[y].eb(x);
	}
	
	int f = bfs(1); 
	
	int d = bfs1(f);
	
	cout << (d % 3 == 1 ? "Second" : "First");
	
	cerr << '\n';
}