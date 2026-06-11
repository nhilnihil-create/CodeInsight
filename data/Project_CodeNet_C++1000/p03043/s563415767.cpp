#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int toss(int dice, int point) {
    int count = 0;
    while (dice < point) {
        dice *= 2;
        count++;
    }

    return count;
}

int main() {
    int n, k;

    cin >> n >> k;

    double ans = 0.0;
    rep(i,n) {
        ans += (1 / (double)n) * (double)pow(0.5, toss(i+1, k));
    }

    printf("%.15f\n", ans);

    return 0;
}