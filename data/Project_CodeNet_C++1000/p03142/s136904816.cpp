#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    vector<int> in(N);
    rep(i, N + M - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        in[b]++;
    }
    vector<int> res(N);
    stack<int> st;
    for(int i = 0; i < in.size(); i++)
        if(in[i] == 0)
            st.push(i);
    while(st.size()) {
        int v = st.top();
        st.pop();
        for(auto &nv : G[v]) {
            in[nv]--;
            if(in[nv] == 0) {
                st.push(nv);
                res[nv] = v + 1;
            }
        }
    }
    rep(i, N) cout << res[i] << endl;
    return 0;
}