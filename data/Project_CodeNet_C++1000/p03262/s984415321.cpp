#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> x(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        x[i] = abs(x[i] - X);
    }

    int ans;
    ans = x[0];
    for (int i = 1; i < N; i++)
    {
        ans = gcd(ans, x[i]);
    }
    
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}