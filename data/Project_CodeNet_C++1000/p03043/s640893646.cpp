#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    double n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        int num = ceil(log2(k/i));
        ans += 1/n*pow(1/2.,num<0?0:num);
    }
    printf("%.12f\n", ans);
    return 0;
}
