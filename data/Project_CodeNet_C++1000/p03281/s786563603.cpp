#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    ll ans = 0;
    rep(i,N) {
        ll tmp = i+1;
        if (tmp % 2 == 0) continue;
        //cout << tmp << endl;
        ll num = 0;
        rep(j,N) {
            if (tmp % (j+1) == 0) {
                //cout << "j+1= " << j+1 << endl;
                num++;
            }
        }
        if (num == 8) ans++;
    }
    cout << ans << endl;

}
