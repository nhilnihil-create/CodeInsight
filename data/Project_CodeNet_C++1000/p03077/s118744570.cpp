#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int main(void){
    ll n;
    cin>>n;
    ll a[5];
    ll m=1000000000000000000,t=0;
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    for(int i=0;i<5;i++){
        if(m>a[i]){
            m=a[i];
            t=i;
        }
    }
    ll ans=4+(n+m-1)/m;
    cout<<ans<<endl;
    
    
}
