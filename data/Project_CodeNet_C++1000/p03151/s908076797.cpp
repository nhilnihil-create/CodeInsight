#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,ans = 0;
    cin >> n;
    vector<long long> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    long long s = 0;
    vector<long long> v;
    rep(i,n){
        if (a[i] < b[i]){
            s+=b[i]-a[i];
            ans++;
        }
        else v.push_back(a[i]-b[i]);
    }
    if (ans){
        sort(v.begin(),v.end(),greater<>());
        long long ds = 0;
        rep(i,v.size()){
            s-=v[i];
            ans++;
            if (ds >= s) break;
        }
        if (ds < s) cout << -1 << endl;
        else cout << ans << endl;
    }
    else cout << 0 << endl;
}