#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

vector<int> G[100010];
deque<int> L;
bool visited[100010];
int ans[100010];

void visit(int v) {
    if (visited[v]) return;
    visited[v] = true;
    for(auto to: G[v]) {
        visit(to);
    }
    L.push_front(v);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, N - 1 + M) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    rep(i, N) {
        visit(i + 1);
    }
    for(auto itr = L.begin(); itr != L.end(); ++itr) {
        for(auto to: G[*itr]) {
            ans[to] = *itr;
        }
    }
    rep(i, N) {
        cout << ans[i + 1] << endl;
    }
   


    return 0;
}
