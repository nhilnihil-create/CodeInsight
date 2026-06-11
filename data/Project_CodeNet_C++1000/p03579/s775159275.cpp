#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P,P> PP;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

ll n, m;
vector<vector<int> > g;
vector<int> visited;
bool odd_cycle = false;

void dfs(int i, int cnt){
    visited[i] = cnt;
    for(auto to : g[i]){
        if(visited[to]==-1) dfs(to,(cnt+1)%2);
        else if(visited[to]==cnt) odd_cycle = true;
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    visited.resize(n,-1);
    REP(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    if(odd_cycle){
        cout << n*(n-1)/2 - m << endl;
    }
    else{
        ll ev=0, od = 0;
        REP(i,n){
            if(visited[i]%2) od++;
            else ev++;
        }
        cout << n*(n-1)/2 - ev*(ev-1)/2 - od*(od-1)/2 - m << endl;
    }
    return 0;
}
