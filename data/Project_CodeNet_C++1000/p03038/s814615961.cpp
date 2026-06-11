#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll n, m; cin >> n >> m;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    V<P<ll, ll> > cb(m);
    for(int i = 0; i < m; i++){
        ll b, c; cin >> b >> c;
        cb[i] = make_pair(c, b);
    }

    sort(ALL(a));
    sort(ALL(cb), greater<P<ll, ll>>());

    V<ll> x = a;
    ll cnt = 0;
    for(int i = 0; i < m; i++){
        auto ite = lower_bound(ALL(a), cb[i].first);
        ll j = ite - a.begin();
        ll c = 0;
        for(int k = cnt; k < j; k++){
            if(x[k] < cb[i].first){
                x[k] = cb[i].first;
                cnt++;
                c++;
            }
            if(c == cb[i].second) break;
        }
    }

    cout << accumulate(ALL(x), 0LL) << endl;


    return 0;
}
