//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 1e+9
const ll MOD = 1000000007;

struct edge {
    int to;
    double cost;
};

// <最短距離, 頂点の番号>
using P = pair<double, int>;

int V;
const int ci = 2e5+ 5;
vector<edge> G[ci];
double d[ci];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) { //cout << "On" << endl;
        P p = que.top();
        que.pop();
        int v = p.second; //cout << "v=" << v << endl;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i]; //cout << "koo" << endl;
            if (d[e.to] > d[v] + e.cost) { //cout << e.cost << endl;
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
ll modPow(ll a, ll n, ll p) {
    if (n == 0) return 1; // 0乗にも対応する場合
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}
vector<int> par;
vector<int> RANK;
void init(int n){
    for(int i = 0; i < n; i++){
        par.pb(i);
        RANK.pb(0);
    }return;
}

int FindRoot(int x){
    if(par[x] == x) return x;
    par[x] = FindRoot(par[x]);
    return par[x];
}

bool isSame(int x, int y){
    return FindRoot(x) == FindRoot(y);
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x == y) return;
    if(RANK[x] > RANK[y]) par[y] = x;
    else {
        par[x] = y;
        if(RANK[x] == RANK[y]){
            RANK[y]++;
        }
    }return;
}


int main() {
    int n, m; cin >> n >> m;
    init(n);
    for(int i  = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        Union(x,y);
    }
 	
  	int ans = 0;
  	rep(i,n) if(par[i] == i) ans++;
  	
  	cout << ans << endl;
}
