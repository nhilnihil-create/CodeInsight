#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    string s;  cin >> s;
    vector<ll> a(26,0);
    rep(i,n) a.at((int)(s.at(i)-'a'))++;
    ll ans = 1;
    rep(i,26) ans = ans * (a.at(i) + 1) % mod;
    cout << ans - 1 << endl;
    return 0;
}