#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1,0);
    rep(i,n) sum[i+1] = sum[i] + a[i];
    map<ll,int> cnt;
    rep(i,n+1) cnt[sum[i]]++;
    ll ans = 0;
    for(auto u : cnt){
        ll num = u.second;
        ans += num * (num-1) / 2;
    }
    cout << ans << endl;
}