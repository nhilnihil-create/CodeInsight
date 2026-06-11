#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, Y; cin >> N >> Y;

    for (int i = 0; i <= N; ++i) {

        for (int j = 0; j <= N; ++j) {

            ll x = i;
            ll y = j;
            ll z = N - x - y;
            if (z < 0) break;
            if (x * 10000 + y * 5000 + z * 1000 == Y) {
                cout << x << " " << y << " " << z << endl;
                exit(0);
            }

        }
    }

    cout << "-1 -1 -1" << endl;

}
