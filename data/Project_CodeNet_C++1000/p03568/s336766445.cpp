#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    int sum = 1, dif = 1;
    rep(i, N) {
        int a;
        cin >> a;

        sum *= 3;
        if (a % 2 == 0)
            dif *= 2;
    }

    cout << sum - dif << endl;

    return 0;
}