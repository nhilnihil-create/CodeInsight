#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
vector<int> e[200000];
int dist[200000];

int main() {
    cin >> n;
    rep(i,n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    fill(dist, dist+n, inf);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int p = que.front(); que.pop();
        for (int to : e[p]) {
            if (dist[to] != inf) continue;
            dist[to] = dist[p] + 1;
            que.push(to);
        }
    }
    int nxt = 0, M = 0;
    rep(i,n) {
        if (dist[i] > M) {
            M = dist[i];
            nxt = i;
        }
    }
    cerr << nxt << " " << M << endl;
    fill(dist, dist+n, inf);
    dist[nxt] = 0;
    que.push(nxt);
    while (!que.empty()) {
        int p = que.front(); que.pop();
        for (int to : e[p]) {
            if (dist[to] != inf) continue;
            dist[to] = dist[p] + 1;
            que.push(to);
        }
    }
    M = 0;
    rep(i,n) M = max(M, dist[i]);
    if (M%3  == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}