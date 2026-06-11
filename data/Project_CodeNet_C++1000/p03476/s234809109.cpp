#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

bool sosuu(ll num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double dtmp = sqrt(num);
    for (int i = 3; i <= dtmp; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    ll N; cin >> N;
    vector<ll> ans(N, 0);
    ll num = pow(10, 5);
    vector<ll> jj(num, 0);

    for (int i = 1; i <= num; i += 2) {
        ll t = (i+1) / 2;
        if (sosuu(i) == true && sosuu(t) == true) {
            jj[i-1] = 1;
        }
    }

    vector<ll> RR(num, 0);
    ll num3 = 0;
    for (int i = 0; i < num; ++i) {
        if (jj[i] == 1) num3++;
        RR[i] = num3;
    }

    ll num2 = 0;
    rep(i,N) {
        ll l, r; cin >> l >> r;
        ll lt = l - 2;
        if (lt < 0) lt = 0;
        ll rt = r - 1;
        if (rt < 0) rt = 0; 
        ans[i] = RR[rt] - RR[lt];
    }
    rep(i,N) {
        cout << ans[i] << endl;
    }



}
