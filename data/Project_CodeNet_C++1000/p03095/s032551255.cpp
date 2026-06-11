#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<int, int> cnt;
    for(char c: s)
        cnt[c] += 1;
    ll mod = 1e9 + 7;
    ll ans = 1;
    for(auto p: cnt) {
        ans *= (p.second+1);
        ans %= mod;
    }
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}


