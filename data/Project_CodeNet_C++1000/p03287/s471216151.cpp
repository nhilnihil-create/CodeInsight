#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n+1, 0);
    rep(i,n){
        s[i+1] = (s[i] + a[i]) % m;
    }
    map<int, int> ma;
    rep(i,n+1) ma[s[i]]++;
    ll ans = 0;
    for(auto p : ma){
        ll num = p.second;
        ans += num * (num-1) / 2;
    }
    cout << ans << endl;
}