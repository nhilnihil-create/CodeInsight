#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N;cin >> N;
    vector<vector<P>> G(N);
    rep(i,N - 1) {
        int a,b,c; cin >> a >> b >> c;
        --a; --b;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    vector<int> color(N,-1);
    color[0] = 0;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int v = st.top(); st.pop();
        for (P &p:G[v]) {
            if (color[p.first] >= 0) continue;
            color[p.first] = (color[v] + p.second)%2;
            st.push(p.first);
        }
    }
    rep(i,N) cout << color[i] << '\n';
    return 0;
}