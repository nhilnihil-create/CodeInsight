#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        int ipt;
        cin >> ipt;
        a[i] = ipt - (i + 1);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    if (n % 2 == 1)
    {
        ans = a[n / 2];
    }
    else
    {
        ans = (a[(n / 2) - 1] + a[n / 2]) / 2;
    }
    ll total = 0;
    rep(i, n)
    {
        total += abs(a[i] - ans);
    }
    cout << total << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
