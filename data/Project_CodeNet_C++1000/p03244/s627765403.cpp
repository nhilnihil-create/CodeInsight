#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;


int main() {
    int N;
    cin >> N;

    int X[100010], Y[100010], ai;
    fill(X, X+100010, 0);
    fill(Y, Y+100010, 0);
    rep(i, N) {
        cin >> ai;
        if (i%2 == 0) X[ai]++;
        else Y[ai]++;
    }

    int onum0 = 0, onum1 = 0, enum0 = 0, enum1 = 0;
    int oi0 = 0, oi1 = 0, ei0 = 0, ei1 = 0;

    rep(i, 100001) {
        if (onum0 <= X[i]) {
            onum1 = onum0;
            oi1 = oi0;
            onum0 = X[i];
            oi0 = i;
        } else if (onum1 <= X[i]) {
            onum1 = X[i];
            oi1 = i;
        }

        if (enum0 <= Y[i]) {
            enum1 = enum0;
            ei1 = ei0;
            enum0 = Y[i];
            ei0 = i;
        } else if (enum1 <= Y[i]) {
            enum1 = Y[i];
            ei1 = i;
        }
    }

    int ans;
    if (oi0 != ei0) ans = N - onum0 - enum0;
    else ans = min(N - onum0 - enum1, N - onum1 - enum0);
    cout << ans << endl;

    return 0;
}