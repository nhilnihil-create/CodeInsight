#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n)
    {
        cin >> a[i];
    }
    vector<ll> counter(40,0);
    rep(i,n)
    {
        rep(j,40)
        {
            ll a_i = a[i];
            if ( (a_i >> j) & 1)
            {
                counter[j]++;
            }
        }
    }
    
    vector<int> bit_k(40);
    k++;
    rep(i,40)
    {
        bit_k[i] = (k >> i)&1;
    }
    ll ans = 0;
    ll temp_ans = 0;
    rep(i,40)
    {
        if (bit_k[i]==0)
        {
            continue;
        }
        temp_ans = 0;
        //cout << i << endl;
        for (int j = 0; j < 40; j++)
        {
            if (j<i)
            {
                temp_ans += max(n - counter[j], counter[j]) * (1ull << j);
                continue;
            }
            if (j==i)
            {
                temp_ans += (counter[j]) * (1ull << j);
                continue;
            }
            temp_ans += (bit_k[j] ? (n - counter[j]) * (1ull << j) : (counter[j]) * (1ull << j));
        }

        //cout << temp_ans << endl;
        ans = max(ans, temp_ans);
    }
    cout << ans << endl;
}