#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define pii pair<int, int>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cerr << #x << ": " << x << '\n'
#define fast_io() ios::sync_with_stdio(false); cin.tie(0);

signed main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> here(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(a[i] > (i == 0 ? 0 : a[i - 1] + 1)){
            cout << -1;
            return 0;
        }
        here[i - a[i]].pb(a[i] - i);
    }
    map<int, int> mp;
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++){
        for(auto x : here[i]){
            mp[x]++;
            if(mp[x] == 1) cnt++;
        }
        ans += cnt - min(1LL, mp[-i]);
        mp[a[i] - i]--;
        if(mp[a[i] - i] == 0) cnt--;
    }
    cout << ans;
    return 0;
}
