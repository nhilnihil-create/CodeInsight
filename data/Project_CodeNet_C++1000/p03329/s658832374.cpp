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
    int n; cin >> n;
    vector<int> buf;
    buf.push_back(1); 
    for (int i = 6; i <= n; i *= 6) buf.push_back(i); 
    for (int i = 9; i <= n; i *= 9) buf.push_back(i); 
    sort(all(buf)); 
    vector<int> dp(n+1, numeric_limits<int>::max());
    for (int c :buf) {
        for(int i = c; i <= n; ++i) {
            if (i==c) dp[i] = 1;
            else dp[i] = min(dp[i], dp[i-c]+1);
        }
    } 
    cout << dp[n] << endl;
    return 0;
}