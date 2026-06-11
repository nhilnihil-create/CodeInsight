#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll sum(ll x){
    ll ans=0;
    while(x>0) ans+=x%10,x/=10;
    return ans;
}
vec ans;
int main(){
    ll k;
    cin>>k;
    rep(i,16){
        ll z=0;
        rep(j,i) z+=9*pow(10,j);
        for(ll j=0;true;j++){
            if(j%10==9) continue;
            ll x=j*pow(10,i)+z;
            if(x<=sum(x)*pow(10,i)) ans.push_back(x);
            else break;
        }
    }
    sort(all(ans));
    rep(i,k) cout<<ans[i+1]<<"\n";
}