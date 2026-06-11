
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;
int a, b;
bool check(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum >= a && sum <= b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        if (check(i))
            ans += i;
    }
    cout << ans << endl;

    return 0;
}

