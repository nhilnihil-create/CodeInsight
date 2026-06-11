#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e5 + 5;
ll n, m, ans, a[N];
map<int, vector<int>>mp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i) a[i] += a[i - 1];
        mp[a[i] % m].push_back(i);
    }
    int rem = 0;
    for(int i = 0; i < n; i++){
        if(i) rem = (a[i - 1]) % m;
        if(!mp.count(rem)) continue;
        if(mp[rem].back() < i) continue;
        int idx = lower_bound(mp[rem].begin(), mp[rem].end(), i) - mp[rem].begin();
        ans += mp[rem].size() - idx;
    }
    cout << ans ;
    return 0;
}
