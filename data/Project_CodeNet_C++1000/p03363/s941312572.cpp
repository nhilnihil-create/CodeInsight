#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a;
    ll sum = 0;
    rep(i,n) {
        int x;
        cin >> x;
        sum += x;
        a.push_back(sum);
    }
    ll ans = 0;
    map<ll,ll> mp;
    rep(i,a.size()){
        mp[a[i]]++;
    }
    for(auto x : mp){
        if(x.first==0) {
            ans += x.second;
        }
            ans += (x.second*(x.second-1)/2);
    }
    cout << ans << endl;

    return 0;
}