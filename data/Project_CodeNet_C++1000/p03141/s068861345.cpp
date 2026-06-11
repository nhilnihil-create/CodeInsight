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

int main()
{
    ll N;
    cin >> N;
    vll A(N), B(N);
    vector<pair<ll, ll>> C(N);
    ll sum = 0;
    rep(i, N)
    {
        cin >> A[i] >> B[i];
        C[i] = {A[i] + B[i], i};
        sum += B[i];
    }
    sort(all(C), greater<pair<int, int>>());
    ll Ta = 0, Ao = 0;
    rep(i, N)
    {
        if (i % 2 == 0)
            Ta += A[C[i].second];
        else
        {
            Ao += B[C[i].second];
        }
    }
    cout << Ta - Ao;
    return 0;
}