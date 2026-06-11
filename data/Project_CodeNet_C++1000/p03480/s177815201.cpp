#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using edge = struct {int to; ll cost;};

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)


//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int ts = n;
    for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]) ts = min(ts, max(i, n-i));
    }
    cout << ts << "\n";
}

int main()
{
    solve();
    return 0;
}
