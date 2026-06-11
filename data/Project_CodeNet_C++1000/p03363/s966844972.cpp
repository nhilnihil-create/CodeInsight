#include<bits/stdc++.h> 
//#include<atcoder/all>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
//using namespace atcoder;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, n) cin >> a[i + 1];
    rep(i, n) a[i + 1] += a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    vector<ll> res;
    int p = a[0];
    int q = 1;
    rep(i, n){
        if (a[i] != a[i + 1]){
            res.pb(q);
            q = 1;
        }
        else q++;
    }
    res.pb(q);
    rep(i, res.size()) ans += res[i] * (res[i] - 1) / 2; 
    cout << ans << endl;
}