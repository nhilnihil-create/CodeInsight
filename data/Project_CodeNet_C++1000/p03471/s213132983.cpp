#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, Y;
    cin >> N >> Y;
    rep(i,N+1) {
        rep(j,N+1) {
            ll a = i;
            ll b = j;
            ll c = N - a - b;
            if (c < 0) c = 0;
            if (a+b+c > N) continue;
            if (a*10000 + b * 5000 + c*1000 == Y) {
                cout << a << " " << b << " " << c << endl;
                exit(0);
            }
        }
    }
    cout << "-1 -1 -1" << endl;

}