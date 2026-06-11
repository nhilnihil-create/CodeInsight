#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        A[i] = a - (i + 1);
    }

    sort(A.begin(), A.end());

    int med;
    if (n % 2 == 0)
        med = round((A[n / 2] + A[n / 2 - 1]) / 2.0);
    else
        med = A[n / 2];

    ll ans = 0;
    rep(i, n)
    {
        ans += abs(A[i] - med);
    }

    cout << ans << endl;
}