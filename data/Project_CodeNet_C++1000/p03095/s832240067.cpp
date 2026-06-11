#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;

int main() {
    int n;
    string s;
    cin >> n >> s;
    //重複を調べる
    vector<int> table(26);
    rep(i,n){
        table[s[i]-'a']++;
    }
    ll ans = 1;
    rep(i,26){
        ans *= table[i]+1;
        ans %= MOD;
    }
    ans--;
    cout << ans << endl;
    return 0;
}