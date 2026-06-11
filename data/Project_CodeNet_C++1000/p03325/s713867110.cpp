#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll c=0;
        while(a[i]%2==0)
        {
            c++;
            a[i]/=2;
        }    
        ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}