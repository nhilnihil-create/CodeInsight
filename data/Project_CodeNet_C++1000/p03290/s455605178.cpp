#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll D, G; cin >> D >> G;
    vector<ll> p(D, 0);
    vector<ll> c(D, 0);
    rep(i,D) {
        ll tmp1, tmp2; cin >> tmp1 >> tmp2;
        p[i] = tmp1;
        c[i] = tmp2;
    }

    ll ans = -1;
    for (int i = 0; i < (1<<D); ++i) {

        ll tmp_p = 0;
        ll tmp_a = 0;
        ll tmp_q = 0;

        for (int j = 0; j < D; ++j) {
            if ((i >> j) & 0x01) { // complete
                tmp_p += (100 * (j+1) * p[j] + c[j]);
                tmp_a += p[j];
            }
            else {
                tmp_q = j;
            }
        }

        if (tmp_p < G) {
            int s1 = 100 * (tmp_q + 1);
            int need = (G - tmp_p + s1 - 1) / s1;
            if (need >= p[tmp_q]) {
                continue;
            }
            tmp_a += need;
        }
        if (ans == -1) {
            ans = tmp_a;
        }
        else if (ans > tmp_a) {
            ans = tmp_a;
        }

    }
    cout << ans << endl;





}
