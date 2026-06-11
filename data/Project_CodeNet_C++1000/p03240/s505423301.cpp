#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,res;
    cin>>n;
    vector<ll> x(n),y(n),h(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]!=0) res=i;
    }
    rep(i,101){
        rep(j,101){
            ll tmph=h[res]+abs(x[res]-i)+abs(y[res]-j);
            bool flag=0;
            rep(k,n){
                if(h[k]!=max(tmph-abs(x[k]-i)-abs(y[k]-j),(ll)0)) break;
                if(k==n-1) flag=1;
            }
            if(flag){
                cout<<i<<' '<<j<<' '<<tmph;
                return 0;
            }
        }
    }
}