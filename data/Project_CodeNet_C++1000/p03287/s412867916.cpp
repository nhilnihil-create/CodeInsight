#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 1e5 + 5;
ll n, m, ans, arr[N], cum[N];
map<ll, vector<ll>>mp;
ll zabat(ll a)
{
    a %= m;
    a += m;
    a %= m;
    return a;
}
ll add(ll a, ll b)
{
    a = zabat(a);
    b = zabat(b);
    return zabat(a + b);
}
ll sub(ll a, ll b)
{
    a = zabat(a);
    b = zabat(b);
    return zabat(a - b);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
        arr[i] = zabat(arr[i]);
        cum[i] = arr[i];
        if(i)   cum[i] = add(cum[i], cum[i - 1]);
        ans += !arr[i];
        mp[cum[i]].push_back(i);
    }
    for(int i = 0;i < n;++i)
    {
        ll want = sub(m, arr[i]);
        want = add(want, cum[i]);
        auto &v = mp[want];
        auto it = upper_bound(v.begin(), v.end(), i);
        ans += v.size() - (it - v.begin());
    }
    cout << ans;
    return 0;
}
