#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    ll a,b,c;cin>>a>>b>>c;
    
    ll ans = min(c,b+a)+b;
    
    if(c-(b+a)>0)ans++;
    
    cout << ans << endl;
    
    
    return 0;
}