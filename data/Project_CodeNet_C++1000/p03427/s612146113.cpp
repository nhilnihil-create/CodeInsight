#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    bool z=false;
    ll n;
    cin>>n;
    ll ans=0;
    while(n!=0){
        ll a=n%10;
        n/=10;
        if(n==0){
            if(z){
                ans+=a-1;
            }
            else{
                ans+=a;
            }
        }
        else if(a==9){
            ans+=a;
        }
        else{
            ans+=9;
            z=true;
        }
    }
    cout<<ans<<endl;
}