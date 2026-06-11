#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll ans=max(2*a-1,2*b-1);
    cout<<max(ans,a+b);
    return 0;


}
