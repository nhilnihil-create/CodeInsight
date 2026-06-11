#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> a(n), s(n+1);
    unordered_map<lli, lli> mp;
    rep(i, n) cin >> a[i];
    rep(i, n) s[i+1] = s[i]+a[i];
    for(int i = 0; i <= n; i++) mp[s[i]]++;
    lli ans = 0;
    for(auto i : mp){
        ans+=i.second*(i.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
