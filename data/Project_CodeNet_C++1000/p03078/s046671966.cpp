#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
ll x, y, z, k;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y >> z >> k;
    ll a[x], b[y], c[z];
    priority_queue<pair<ll, ll>>pq;
    for(int i = 0;i < x;++i)
        cin >> a[i];
    for(int i = 0;i < y;++i)
        cin >> b[i];
    for(int i = 0;i < z;++i)
        cin >> c[i];
    sort(c, c + z);
    reverse(c, c + z);
    for(int i = 0;i < x;++i)
        for(int j = 0;j < y;++j)
            pq.push({a[i] + b[j] + c[0], 1});
    vector<ll>ans;
    while(k--)
    {
        pair<ll, ll>tp = pq.top();
        pq.pop();
        ans.push_back(tp.F);
        if(tp.S < z)
        {
            tp.F -= c[tp.S - 1];
            tp.F += c[tp.S];
            pq.push({tp.F, tp.S + 1});
        }
    }
    for(auto it : ans)
        cout << it << '\n';
    return 0;
}
