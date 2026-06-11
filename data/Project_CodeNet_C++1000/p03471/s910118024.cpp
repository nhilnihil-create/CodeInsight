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
            int k = N - i - j;
            if (k < 0) continue;
            if (i * 10000 + j * 5000 + k * 1000 == Y) {
                cout << i << " " << j << " " << k << endl;
                exit(0);
            }
        }
    }
    cout << "-1 -1 -1" << endl;


}
