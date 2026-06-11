#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    double a = 1.0 / n;
    double b = 1.0 / 2;
    double ans = 0.0;
    //現在の得点 = i
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, memo = i;
        while (k > memo)
        {
            memo *= 2;
            cnt++;
        }
        ans += a * pow(b, cnt);
    }
    printf("%.12f\n", ans);
    return 0;
}