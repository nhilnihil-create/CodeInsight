#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e5 + 100;
const int oo = 1e18;
const int mod   = 1e9 + 7;

int n, m;
int name[N], cnt[N][2];
bool visit[N];
vector<int> vi[N];

void solve()    {
    queue<int> pq;

    int ans = n;
    FOR(i, 1, n) if(!(cnt[i][0] * cnt[i][1]))
        ans --, pq.push(i), visit[i] = true;
    while(!pq.empty())  {
        int u = pq.front(); pq.pop();
        for(auto v: vi[u]) if(!visit[v]){
            cnt[v][name[u]] --;
            if(!cnt[v][name[u]]) {
                visit[v] = 1;
                pq.push(v);
                ans --;
            }
        }
    }
    if(!ans) cout << "No";
    else cout << "Yes";
}

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, n) {
        char c; cin >> c;
        name[i] = c - 'A';
    }
    FOR(i, 1, m)    {
        int u, v; cin >> u >> v;
        vi[u].pb(v); vi[v].pb(u);
        cnt[u][ name[v] ] ++;
        cnt[v][ name[u] ] ++;
    }
    return solve(), 0;
}
