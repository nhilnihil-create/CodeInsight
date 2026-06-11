#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    string s, t;
    cin >> s >> t;
    if (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
