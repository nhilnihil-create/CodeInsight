#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll k,a,b;
    cin>>k>>a>>b;
    if(b-a<=2){
        cout<<k+1<<endl;
    }
    else{
        ll x=k-(a-1);
        ll ans=a;
        if(x%2==1){
            x--;
            ans++;
        }
        ans+=(b-a)*x/2;
        cout<<ans<<endl;
    }
}