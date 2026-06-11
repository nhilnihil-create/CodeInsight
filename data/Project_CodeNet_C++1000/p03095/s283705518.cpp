#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    map<char, ll> M;
    rep(i, s.length())
    {
        M[s[i]]++;
    }

    ll ans = 1;
    for (auto p : M)
    {
        ans = (ans * (p.second + 1)) % MOD;
    }

    ans = (ans - 1) % MOD;

    cout << ans << endl;
}

//なんでわからんかった