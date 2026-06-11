#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

void dfs(const vector<vector<int> >& e, int node, vector<int>& visited) {
    visited[node] = 1;

    auto& c = e[node];
    rep(i, c.size()) {
        if (visited[c[i]] <= 0) {
            dfs(e, c[i], visited);
        }        
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    
int            bridge = 0;
    rep(ei, m) {
        vector<vector<int> > e(n, vector<int>());
        rep(i, m) {
            if (i == ei) {
                continue;
            }
            e[a[i] - 1].push_back(b[i] - 1);
            e[b[i] - 1].push_back(a[i] - 1);
        }

        vector<int> visited(n);
        dfs(e, 0, visited);

        bool ok = true;
        rep(i, n) {
            if (visited[i] <= 0){
                ok = false;
                break;
            }
        }

        if (ok == false) {
            bridge++;
        }

    }

    put(bridge);

    return 0;
}