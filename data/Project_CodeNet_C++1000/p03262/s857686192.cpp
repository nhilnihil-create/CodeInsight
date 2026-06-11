#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,a;
    cin>>n>>x;a=x;
    ll l1[n+5];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(i==1)x=__gcd(abs(a-l1[i]),abs(a-l1[i]));
        else x=__gcd(x,abs(a-l1[i]));
    }
    cout<<x<<endl;
}
