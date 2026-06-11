#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    rep(i, 0, n){
        int k;
        cin >> k;
        vector<int> a(k);
        rep(j, 0, k){
            cin >> a[j];
            mp[a[j]]++;
        }
    }
    int ans = 0;
    for(auto i : mp){
        if(i.second == n) ans++;
    }
    cout << ans << endl;
    return 0;
}
