#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int val(int num){
    int res = 0;
    while(num > 0){
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int ans = 1e9;
    for (int a = 1; a < n; a++) {
        ans = min(ans, val(a) + val(n - a));
    }
    cout << ans << endl;
}