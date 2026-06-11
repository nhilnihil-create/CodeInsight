#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    ll maxv = N / 4;

    if (N % 4 == 0) {
        cout << "Yes" << endl;
        exit(0);
    }

    rep (i, maxv) {
        ll k = i * 4;
        if ((N - k) % 7 == 0) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}
