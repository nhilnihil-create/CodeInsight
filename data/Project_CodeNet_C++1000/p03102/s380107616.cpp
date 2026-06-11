#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,m,c;
    cin>>n>>m>>c;
    vector<ll> b;
    ll tmp;
    rep(i,m){
        cin>>tmp;
        b.push_back(tmp);
    }
    ll ans=0;
    ll a;
    rep(i,n){
        ll sum=0;
        rep(j,m){
            cin>>a;
            sum+=a*b[j];
        }
        if((sum+c)>0)ans++;
    }

    cout<<ans<<endl;


}

