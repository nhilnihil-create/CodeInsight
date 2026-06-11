#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    ll A,B,C,X;
    cin >> A >> B >> C >> X;
    ll count = 0;
    rep(i,A + 1) {
        rep(j,B + 1) {
            rep(k,C + 1) {
                if (X == 500*i + 100*j + 50*k) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}

