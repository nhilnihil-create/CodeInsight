#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    if (n < 10) {
        return n;
    }
    if (n % 10 == 9) {
        return 9 + solve(n / 10);
    } else {
        return 9 + solve((n / 10) - 1);
    }
}
 
int main() {
    long long  n;
    cin >> n;
    long long ans = solve(n);
    cout << ans << endl;
    return 0;
}
 