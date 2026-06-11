#include <bits/stdc++.h>
using namespace std;

int digitcul(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    int ans = 1e9;
    for (int i=1; i<=n/2+1; ++i) {
        int a = i, b = n - i;
        int sum = digitcul(a) + digitcul(b);
        ans = min(ans, sum);
    }
    cout << ans << endl;
}