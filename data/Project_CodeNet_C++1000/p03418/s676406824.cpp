#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i=k+1;i<=n;i++){
        ll t = n/i * (i-k);
        t += max(n%i - k + 1,0LL);
        ans += t;
    }
    if(k==0){
        ans = n*n;
    }
    cout << ans << endl;
}