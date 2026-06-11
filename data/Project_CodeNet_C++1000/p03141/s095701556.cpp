#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    ll ans = 0;
    rep(i, n){
        ll a, b;
        cin>>a>>b;
        ans -= b;
        v[i] = a+b;
    }
    sort(v.begin(), v.end(), greater<ll>());
    for(int i = 0;i<=n-1;i+=2){
        ans += v[i];
    }
    cout<<ans<<endl;
}