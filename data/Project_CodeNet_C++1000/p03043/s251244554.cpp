#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double calc(int num, int K)
{
    double res = 1.;
    while(num < K)
    {
        res *= 0.5;
        num *= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    double ans = 0.;
    for(int i=1; i<=N; i++)
    {
        ans += calc(i, K) / N;
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
