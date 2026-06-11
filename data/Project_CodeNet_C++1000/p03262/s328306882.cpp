#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n),vv(n);

    ll m=INF;
    rep(i,0,n){
        cin>>v.at(i);
        vv.at(i)=abs(v.at(i)-x);
    }
    ll ans=0;
    rep(i,0,vv.size()-1){
        vv.at(i+1)=__gcd(vv.at(i),vv.at(i+1));
    }
    cout<<vv.at(n-1)<<endl;
return 0;
}