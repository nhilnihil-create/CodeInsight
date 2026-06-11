#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    ll a, b, c, k;
    cin>>a>>b>>c>>k;
    ll now = max(a, b);
    now = max(now, c);
    ll ans = a+b+c-now;
    rep(i, k){
        now *= 2;
    }
    ans += now;
    cout<<ans<<endl;
    return 0;
}