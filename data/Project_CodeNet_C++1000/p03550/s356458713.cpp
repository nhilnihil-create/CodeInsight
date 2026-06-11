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
    int n, z, w;
    cin >> n >> z >> w;
    int a[n];
    REP(i, n) cin >> a[i];
    if(n == 1) {
        cout << abs(a[0] - w) << endl;
    }
    else{
        cout << max(abs(a[n-1] - w), abs(a[n-1]-a[n-2])) << endl;
    }
}

int main()
{
    solve();
    return 0;
}