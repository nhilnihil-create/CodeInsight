#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll n){
    ll m = n+1;
    ll ans = 0;
    for(int i=0;i<50;i++){
        ll tmp = 0;
        ll loop = 1LL<<(i+1);
        //cout << "loop" << i << "=" << loop << endl;
        tmp += m/loop * (loop/2);
        tmp += max(0LL,m%loop-loop/2);
        if(tmp%2==1) ans += (1LL<<i);
    }
    return ans;
}

int main(void){
    ll a,b;
    cin >> a >> b;
    ll ans = calc(b)^calc(a-1);
    cout << ans << endl;
    //cout << calc(a) << ", " << calc(b) << endl;
}