#include <bits/stdc++.h>

using ll = long long;

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)

using namespace std;

//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    auto max = max_element(a.begin(), a.end());
    auto min = min_element(a.begin(), a.end());
    int maxIndex = distance(a.begin(), max);
    int minIndex = distance(a.begin(), min);
    if (a[maxIndex] >= 0 && a[minIndex] >= 0)
    {
        cout << n - 1 << "\n";
        REP(i, n - 1) cout << i + 1 << " " << i + 2 << "\n";
    }
    else if (a[maxIndex] < 0 && a[minIndex] < 0)
    {
        cout << n - 1 << "\n";
        REP(i, n - 1) cout << n - i << " " << n - i - 1 << "\n";
    }
    else
    {
        cout << 2*n-1 << "\n";
        if (abs(a[maxIndex]) >= abs(a[minIndex]))
        {
            REP(i, n) cout << maxIndex+1 << " " << i+1 << "\n";
            REP(i, n - 1) cout << i + 1 << " " << i+2 << "\n";
        }
        else
        {
            REP(i, n) cout << minIndex+1 << " " << i+1 << "\n";
            REP(i, n-1) cout << n-i << " " << n-i-1 << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}