#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);

    rep(i,n) cin>>a[i];
    vector<ll> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+a[i];

    vector<ll> v;
    rep(l,n){
        for(int r=l;r<n;r++){
            v.push_back(s[r+1]-s[l]);
        }
    }

    int m=v.size();
    sort(all(v));
    //rep(i,m) cout<<v[i]<<" ";
    //cout<<endl;
    vector<int> ok(m,1);

    ll ans=0;
    for(int d=60;d>=0;d--){
        ll msk=1LL<<d;
        int cnt=0;
        rep(i,m){
            if((v[i] & msk) && ok[i]) cnt++;
        }
        //cout<<d<<" "<<cnt<<endl;
        if(k<=cnt){
            ans+=msk;
            rep(i,m){
                if(!(v[i] & msk) && ok[i]) ok[i]=0;
            }
        }
    }

    cout<<ans<<endl;
}