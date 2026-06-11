#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())

const int LINF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1e18;



bool isOK(int index, ll key, vector<ll>& vc)
{
    if(vc[index]>=key) return true;
    return false;
}



    int binary_search_self(ll key, vector<ll> &vc)
{
    int left = -1; int right = sz(vc);
    int mid;
    while (right-left>1)
    {
        int mid = left + (right-left)/2;
        if(isOK(mid, key, vc))
        {
            right = mid;
        }else
        {
            left = mid;
        }
    }
    return right;
}

ll mn_gen(int index, ll key, vector<ll> &vc)
{
    if (index == -1)
    {
        return vc[0];
    }
    if (index == sz(vc))
    {
        return vc[index - 1];
    }
    return min(abs(key - vc[index]), abs(key - vc[index - 1]));
}

int main()
{
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s;
    vector<ll> t;
    vector<ll> x;
    
    x.resize(q);
    s.push_back(-LLINF);
    ll temp;
    rep(i,a)
    {
        
        cin >> temp;
        s.push_back(temp);
    }
    s.push_back(LLINF);
    t.push_back(-LLINF);
    rep(i, b)
    {
        cin >> temp;
        t.push_back(temp);
    }
    t.push_back(LLINF);
    rep(i,q)
    {
        cin >> x[i];
    }

    vector<ll> ans(q);
    rep(i,q)
    {
        
        auto s_index = lower_bound(s.begin(), s.end(),x[i]);
        auto t_index = lower_bound(t.begin(), t.end(),x[i]);
        ll ans_temp = LLINF;
        for(auto u: {*s_index, *(s_index-1)})
        {
            for (auto v : {*t_index, *(t_index - 1)})
            {
                ans_temp =min(ans_temp, min(abs(x[i] - u) + abs(v - u),abs(x[i] - v) + abs(v - u)));
            }
        }
        ans[i] = ans_temp;
    }
    rep(i,q)
    {
        cout << ans[i] << endl;
    }
}