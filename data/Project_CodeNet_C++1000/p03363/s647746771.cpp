#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n;
    cin >> n ;
    vector<ll> cum(n+1,0);
    for(int i = 1;i<=n;i++){
        int a;cin >> a;
        cum[i] = cum[i-1] + a;
    }

    map<ll,int> mp;
    
    rep(i,n+1){
        mp[cum[i]] += 1;
    }

    ll cnt = 0;

    for(auto p:mp){
        cnt += ll(p.second)*ll(p.second-1)/2;
    }
    cout << cnt << endl;
 }