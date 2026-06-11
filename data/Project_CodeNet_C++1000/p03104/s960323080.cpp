#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;

    ll tot;
    for(ll x=1;x<=b;x*=2) {
        ll ca = ((a-1)/(x*2)) * (x) + max((a-1)%(x*2)-x+1,(ll)0);
        ll cb = (b/(x*2)) * (x) + max((b)%(x*2)-x+1,(ll)0);
        ll c = cb-ca;
        // cout << x << " " << cb << " " << ca << endl;
        
        if(c%2==1) tot += x;
    }
    cout << tot << endl;
    return 0;
}