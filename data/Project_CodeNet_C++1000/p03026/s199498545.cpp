#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n;
    ll sum = 0;
    cin >> n;
    vector<vector<int> > G(n);
    vector<int> dp(n, -1), answer(n), c(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, n) {
        cin >> c[i];
        sum += c[i];
    }
    sort(c.begin(), c.end(), greater<int>());
    // bfs
    queue<int> que;
    que.push(0);
    dp[0] = c[0];
    int count = 0;
    while(que.size()) {
        int p = que.front();
        que.pop();
        rep(i, G[p].size()) {
            int to = G[p][i];
            if(dp[to] == -1) {
                count++;
                dp[to] = c[count];
                que.push(to);
            }
        }
    }
    cout << sum - c[0] << endl;
    rep(i, n) {
        if(i != n-1) cout << dp[i] << " ";
        else cout << dp[i] << endl;
    } 
}