#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int n;
    string s;
    cin >> n >> s;
    ll ans = 1;
    vector<int> v(25);
    rep(i, n){
        v[(int)s[i]-97]++;
    }
    rep(i, 26){
        ans %= MOD;
        ans = (ans%MOD * (v[i]+1))%MOD;
    }
    cout << ans-1 << endl;
    return 0;
}


