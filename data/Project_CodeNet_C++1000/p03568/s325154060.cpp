#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    int sum = 1;
    int minus = 1;
    rep(i, n) {
        int tmp; cin >> tmp;
        sum *= 3;
        if (tmp % 2 == 0) {
            minus *= 2;
        }
    }
    cout << sum-minus << endl;
}