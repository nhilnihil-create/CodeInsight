//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ll n;
    cin >> n;
    double q = sqrt(n);
    ll ans = 0;

    vi aa;

    for(int i=0; ++i<q;) {
        if(n%i == 0) {
            aa.push_back(i);
            aa.push_back(n/i);
        } 
    }

    for(ll i:aa) {
        if(i-1 && n%(i-1) == n/(i-1)) {
            ans += i-1;
        }
    }

    cout << ans << endl;
}