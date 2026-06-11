#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> rui(n); //今までた白の累積和
    rep(i, n)
    {
        if (i == 0)
        {
            if (s[i] == '.')
                rui[i]++;
        }
        else if (s[i] == '.')
        {
            rui[i] = rui[i - 1] + 1;
        }
        else
        {
            rui[i] = rui[i - 1];
        }
    }

    ll w = rui[n - 1];
    ll b = n - w;

    ll ans = min(w, b);
    rep(i, n - 1)
    {
        ll tmp=i+1-rui[i]+w-rui[i];
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;
}