#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const int INF = 1LL<<30;

int N,K;
ll A[1010];
ll sm[1010];

int main() {
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    sm[0]=A[0];
    for(int i=1;i<N;i++) sm[i]=sm[i-1]+A[i];

    vector<ll> v;
    for(int l=0;l<N;l++){
        for(int r=l;r<N;r++){
            ll tot=sm[r];
            if(l) tot-=sm[l-1];
            v.push_back(tot);
        }
    }

    int n=v.size();
    vector<int> ok(n,1);

    ll ans=0;
    for(int d=60;d>=0;d--){
        ll msk=1LL<<d;
        int cnt=0;
        rep(i,n){
            if(v[i] & msk && ok[i]) cnt++;
        }
        if(K<=cnt){
            ans+=msk;
            rep(i,n){
                if(!(v[i] & msk) && ok[i]) ok[i]=0;
            }
        }
    }

    cout<<ans<<endl;
}