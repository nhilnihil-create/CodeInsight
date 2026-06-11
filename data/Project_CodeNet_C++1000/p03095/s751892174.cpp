#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
ll mod = 1e9+7;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int>mp;
    for(char c : s) mp[c]++;
    ll ans = 1;
    for(auto x : mp){
        ans*=(x.second+1)%mod;
        ans%=mod;
    }
    cout << ans-1 << endl;
    return 0;
}