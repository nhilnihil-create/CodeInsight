#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,k;
    cin >> n >> k;
    vl a(n+1,0);
    rep(i,n){
        int t;cin >> t;
        a[i+1] = t + a[i];
    }
    vl b;
    rep(i,n){
        for(int j=i+1;j<=n;j++){
            b.push_back(a[j] - a[i]);
        }
    }
    ll ans = 0;
    sort(b.begin(),b.end(),greater<ll>());
    for(int i=49;i>=0;i--){
        vl d;
        rep(j,b.size()) if(b[j]>>i & 1){
            d.push_back(b[j]);
        }
        if(d.size()>=k){
            b = d;
            ans |= 1LL<<i;
        }
    }
    cout << ans << endl;
}