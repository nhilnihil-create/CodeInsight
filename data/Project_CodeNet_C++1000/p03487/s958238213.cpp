#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(auto x : mp){
        if(x.first==x.second) continue;
        if(x.second > x.first) ans+=x.second-x.first;
        else ans += x.second;
    }
    cout << ans << endl;
    return 0;
}