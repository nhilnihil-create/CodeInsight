#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> C(n); ll sum = 0;
    rep(i, n){
        cin >> C[i];
        sum += C[i];
    }
    sort(all(C), greater<ll>());
    sum -= C[0];
    vector<int> res(n, INF);
    queue<int> que; que.push(0);
    res[0] = C[0]; int index = 1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int g: G[v]){
            if(res[g] != INF) continue;
            res[g] = C[index];
            index++;
            que.push(g);
        }
    }
    cout << sum << ln;
    rep(i, n) cout << res[i] << " ";
    cout << ln;
}
