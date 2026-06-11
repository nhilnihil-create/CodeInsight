#include <bits/stdc++.h>

using namespace std;

void solve() {
    long double N, K;
    cin >> N >> K;

    long double ans;
    ans = 0;
    for (int i = 1; i <= N; i++)
    {   
        if (i < K)
        {
            ans += powl(0.5, ceil(log2(K/i)));
        }
        else
        {
            ans += 1;
        }
        
    }
    ans = ans / N;
    cout << fixed << setprecision(15) << ans << endl;
}

int main() {
    solve();
    return 0;
}