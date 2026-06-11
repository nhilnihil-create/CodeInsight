#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    LL N; cin >> N;
    for (LL i = 1; i <= 3500; ++i) {
        for (LL j = 1; j <= 3500; ++j) {
            LL n1 = 4*i*j - N*j - N*i;
            LL n2 = N*i*j;
            if (n1 > 0 && n2 > 0 && n2 % n1 == 0) {
                cout << i << ' ' << j << ' ' << n2/n1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
