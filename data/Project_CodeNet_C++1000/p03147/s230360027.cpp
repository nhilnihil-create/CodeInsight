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
    ll n;
    cin>>n;
    ll ans=0,prev=0,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x-prev>0)
            ans+=x-prev;
        prev=x;
    }
    
    cout<<ans<<endl;
    return 0;
}
