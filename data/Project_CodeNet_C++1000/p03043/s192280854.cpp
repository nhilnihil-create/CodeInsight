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
            ans += pow(2, 17- ceil(log2(K/i)));
        }
        else
        {
            ans += 131072;
        }
        
    }
    ans = ans / N / 131072;
    cout << fixed << setprecision(15) << ans << endl;
}

int main() {
    solve();
    return 0;
}