#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000000+7;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<char,int> mp;
    rep(i,n) {
        ++mp[s[i]];
    }
    ll ans = 1;
    for (auto tmp_mp:mp){
      ans = (ans*((ll)tmp_mp.second+1LL)%mod)%mod;
    }
    cout << ans - 1LL << endl;
    return 0;
}
