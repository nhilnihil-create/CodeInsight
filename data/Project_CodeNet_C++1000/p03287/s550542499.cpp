#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n, k; cin >> n >> k;

    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n+1); s[0] = 0;
    rep(i,n) s[i+1] = (s[i] + a[i]) %k;

    map<int,int> mp;
    ll ans = 0;

    rep(i,n+1){
        ans += mp[s[i]];
        mp[s[i]]++;
    }

    dunk(ans);
}
