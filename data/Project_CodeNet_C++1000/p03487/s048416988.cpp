#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;


int main(){
    int n;cin >>n;
    map<ll,int> mp;
    rep(i,n){
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    for(auto ele : mp){
        if(ele.first==ele.second)continue;
        if(ele.first<ele.second)ans+=ele.second - ele.first;
        else ans += ele.second;
    }
    cout << ans <<endl;
    return 0;

}