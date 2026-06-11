#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long int res = 0;
    for(int i = k + 1; i <= n; i++){
        res += (i - k) * (n / i) + max((n % i - (k - 1) * (k != 0)), 0);
    }
    cout << res << endl;
    return 0;
}