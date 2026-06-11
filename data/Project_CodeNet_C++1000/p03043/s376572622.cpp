#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    double k,ans;

    cin >> n >> k;

    ans = 0;
    double a = 1.0 / n;   //サイコロの確率
    for (int i = 1;i <= n;++i) {
        double bb = log(k / i) / log(2);
        int b1 = ceil(log(k / i) / log(2)); //べき乗→コインの連続回数
        if (b1 > 0) {
            double b = pow(0.5, b1);
            ans += a * b;
        }
        else
            ans += a;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
