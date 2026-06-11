#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_map<ll,int> mp;

    ll now = 0;
    ll ans = 0;

    mp[0]++;

    for(int i = 0; i < n; i++){
        now += a[i];
        ans += mp[now];
        mp[now]++;
    }

    cout << ans << endl;

    return 0;
}