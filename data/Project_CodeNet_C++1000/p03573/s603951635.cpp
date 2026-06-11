#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==b) cout<<c<<endl;
    else if(a==c) cout<<b<<endl;
    else cout<<a<<endl;
    return 0;
}
