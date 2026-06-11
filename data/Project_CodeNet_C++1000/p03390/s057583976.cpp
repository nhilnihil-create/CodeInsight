#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int q;
    ll a, b;
    scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld", &a, &b);
        if (a > b) swap(a, b);
        ll ans=0;
        ll c=a*b;
        ll d=sqrt(c);
        if(d*d==c) d--;
        if(a==b||a==b+1)
           ans=2*a-2;
        else if(d*(d+1)>=a*b)
            ans=2*d-2;
        else ans=2*d-1;
        cout<<ans<<endl;
    }
    return 0;
}
