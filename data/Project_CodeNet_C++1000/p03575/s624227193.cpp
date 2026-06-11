#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> es(n);
    vector<int> dp(n, 0);
    rep(i, m) {
        int a,b; cin >> a >> b;
        --a; --b;
        es[a].push_back(b);
        es[b].push_back(a);
        dp[a]++; dp[b]++;
    }  
    queue<int> st;
    rep(i, n) if (dp[i] == 1) st.push(i);
    int cnt = 0; 
    while (!st.empty()) {
        int a = st.front(); st.pop();
        if (dp[a] > 0) {
            dp[a]--;
            ++cnt;
        }
        for (int b : es[a]) {
            if (dp[b] > 0) dp[b]--;
            if (dp[b] == 1) st.push(b);
        }
    } 
    cout << cnt << endl;
    return 0;
}