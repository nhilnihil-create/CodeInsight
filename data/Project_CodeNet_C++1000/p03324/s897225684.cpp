#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll D, N; cin >> D >> N;
    //cout << "D = " << D << ",N = " << N << endl;
    if (N == 100) N = 101;
    ll ans = 0;
    if (D == 0) {
        ans = N;
        cout << ans << endl;
    }
    else if (D == 1) {
        ans = 100 * N;
        cout << ans  << endl;
    }
    else if (D == 2) {
        ans = 100 * 100 * N;
        cout << ans << endl;
    }


}
