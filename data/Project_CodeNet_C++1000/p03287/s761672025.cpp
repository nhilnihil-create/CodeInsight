#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    rep(i,n)cin >> a[i];

    map<ll,ll> mp;

    ll sum = 0;
    ll ans = 0;
    rep(i,n){
        sum += a[i];
        sum %= m;
        mp[sum]++;
        if(sum == 0)ans++;
    }

    // mp[3] = 5;

    for(auto p : mp){
        if(p.second >= 2){
            ans += p.second * (p.second - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}


