#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for(ll i = 2; i*i <= n; i++) {
        if (n%i != 0) continue;
        res.emplace_back(i,0);
        while (n%i == 0) {
            n/=i;
            res.back().second++;
        }
    }
    if (n!=1) res.emplace_back(n,1);
    return res;
}

int main() 
{
    int n;
    cin >> n;

    map<ll, int> mp;
    for (int i=1; i<=n; i++) {
        auto fact  =factorize(i);
        for (auto p : fact) {
            mp[p.first] += p.second;
        }
    }

    int over3 = 0;
    int over5 = 0;
    int over15 = 0;
    int over25 = 0;
    int over75 = 0;

    for(auto v : mp) {
        int x = v.second+1;
        if (x>=3) over3++;
        if (x>=5) over5++;
        if (x>=15) over15++;
        if (x>=25) over25++;
        if (x>=75) over75++;        
    }

    ll ans = 0;
    // 75
    ans += over75;
    // 25 * 3
    ans += over25 * max(0, (over3-1));
    // 15 * 5
    ans += over15 * max(0, (over5-1));
    // 5 * 5 * 3
    ans += over5*(over5-1)/2 * max(0, (over3-2));

    cout << ans << endl;

    return 0;
}
