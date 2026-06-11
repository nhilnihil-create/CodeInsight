#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

bool isPalindrome(int n) {
    return (n / 10000) == (n % 10) && (n / 1000 % 10) == (n / 10 % 10);
}

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (isPalindrome(i))
            cnt++;
    }
    cout << cnt << endl;
}