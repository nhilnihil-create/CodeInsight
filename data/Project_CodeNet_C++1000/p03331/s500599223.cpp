#include <bits/stdc++.h>
using namespace std;
int solve(int N)
{
    int ans = 0;
    do {
        ans += (N % 10);
        N /= 10;
    } while (N);
    return ans == 1 ? 10 : ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    auto ans = solve(N);
    cout << ans << '\n';
    return 0;
}