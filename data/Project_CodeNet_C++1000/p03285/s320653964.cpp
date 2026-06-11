#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<bool> dp(100);
    dp.at(0) = false, dp.at(1) = false, dp.at(2) = false, dp.at(3) = true,dp.at(4) = false, dp.at(5) = false, dp.at(6) = true;
    for (int i = 7; i < 100; i++) {
        dp.at(i) = dp.at(i - 4) || dp.at(i - 7);
    }
    if (dp.at(N - 1)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}