#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

//最大公約数(引数の型に注意)
ll gcd(ll a, ll b)
{
    if (a * b == 0)
        return max(a, b);
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    return gcd(a % b, b);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    //iまでの累積GCD(iも含む),iからn-1までの累積GCD(iも含む)
    vector<ll> L(n), R(n);
    ll tmp = 0;
    rep(i, n)
    {
        tmp = gcd(A[i], tmp);
        L[i] = tmp;
    }
    tmp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        tmp = gcd(A[i], tmp);
        R[i] = tmp;
    }

    ll ma = 0;
    rep(i, n)
    {
        ll tmp;
        if (i == 0)
            tmp = R[i + 1];
        else if (i == n - 1)
            tmp = L[i - 1];
        else
            tmp = gcd(L[i - 1], R[i + 1]);
        ma = max(tmp, ma);
    }

    cout << ma << endl;
}