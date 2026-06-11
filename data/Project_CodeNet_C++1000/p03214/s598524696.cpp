#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
#define vcin(a)                          \
    for (int i = 0; i < (a).size(); i++) \
        cin >> (a)[i];

int main()
{
    int N, sum = 0;
    cin >> N;
    vint a(N);
    rep(i, N)
    {
        cin >> a[i];
        sum += a[i];
    }
    double ave = (double)sum / (double)N;
    double dif = INT_MAX, ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (dif >= abs(a[i] - ave))
        {
            ans = i;
            dif = abs(a[i] - ave);
        }
    }
    cout << ans;
    return 0;
}