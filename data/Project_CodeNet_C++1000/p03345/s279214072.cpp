#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a,b ,c,k;
    cin>>a>>b>>c>>k;
    ll ans =0;
    if( k%2==0)
        ans = a-b;
    else ans = b-a;

    if( ans >1e18)
        cout<<"Unfair";
    else cout<<ans;
}