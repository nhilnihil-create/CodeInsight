#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll n = a*x+b*y;
    ll m = 2*c*min(x,y);
    if(x<y) m += (y-x) * min(b, 2*c);
    else if(x>y) m += (x-y) * min(a, 2*c);
    cout<<min(n,m);
}