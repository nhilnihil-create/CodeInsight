#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,y;
    cin>>n>>y;
    for(ll i=0;i<=n;i++) 
    {
        for(ll j=0;j<=n-i;j++)
        {
            if(i*10000+j*5000+(n-i-j)*1000==y) 
            {
                cout<<i <<" "<<j<<" "<<n - i - j<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}