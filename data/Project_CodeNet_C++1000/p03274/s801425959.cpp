#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, K; cin >> N >> K;
    vector<ll> x(N, 0);
    rep(i,N) {
        ll tmp; cin >> tmp;
        x[i] = tmp;
    }
    ll num = N - K + 1;
    ll ans = 0;
    rep(i,num) {

        ll l = abs(x[i]);
        ll r = abs(x[i+K-1]);
        ll dif = abs(x[i+K-1]-x[i]);
        ll tmp = 0;
        if ((l+dif) > (r+dif)) {
            tmp = r+dif;
        }
        else {
            tmp = l+dif;
        }
        if (i == 0) {
            ans = tmp;
        }
        else if (ans > tmp) {
            ans = tmp;
        }

    }
    cout << ans << endl;



}
