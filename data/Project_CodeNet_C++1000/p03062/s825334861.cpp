#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main() {
    int N;
    cin >> N;
    int m = INT_MAX;
    int cnt = 0;
    ll sum = 0;
    rep(i, N) {
        int x;
        cin >> x;
        cnt += (x < 0);
        m = min(m, abs(x));
        sum += abs(x);
    }
    if (cnt % 2 == 0)
        cout << sum << endl;
    else
        cout << sum - m * 2 << endl;
}