#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int d_sum(int n)
{
    if (n < 10)
        return n;
    return d_sum(n / 10) + n % 10;
}

int main()
{
    int N, sum;
    cin >> N;
    if (N % d_sum(N) == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
