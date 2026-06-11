#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using edge = struct {int to; ll cost;};

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
#define INF (1 << 29)


//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

void solve(){
    int a, b, c, d;
    cin >> a >> b>> c >> d;
    cout << min(a, b) + min(c, d) << "\n";
}

int main()
{
    solve();
    return 0;
}