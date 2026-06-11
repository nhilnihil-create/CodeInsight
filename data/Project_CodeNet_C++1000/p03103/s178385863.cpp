#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> p;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        p.push_back(make_pair(a, b));

    }
    ll cnt = 0;
    ll cost = 0;
    sort(p.begin(), p.end());
    for (ll i = 0; i < n; i++)
    {
        ll a = p[i].first;
        ll b = p[i].second;
        ll diff = m - cnt;
        if(diff>b)
        {
            cost += a*b;
            cnt += b;
        }
        else
        {
            cost += a * diff;
            cnt += diff;
        }
    }
    cout << cost << endl;
    return 0;
}