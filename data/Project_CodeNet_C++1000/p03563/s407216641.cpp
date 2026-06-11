// WeirdBugsButOkay

# include <bits/stdc++.h>

# define ll long long
# define ld long double
# define pii pair <int,int>
# define pll pair <ll,ll>
# define mp make_pair
# define pb push_back
# define ff first
# define ss second
# define endl '\n'

using namespace std;

ll pow3(ll a, ll b, ll m = 1000000007)
{
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll r, g;
    cin >> r >> g;
    cout << 2 * g - r << endl;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q = 1;
    //cin >> q;
    for(ll i = 0; i < q; i++)
    {
        solve();
    }
    return 0;
}
