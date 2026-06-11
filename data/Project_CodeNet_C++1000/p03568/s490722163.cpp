#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e=0,o=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]&1)
            o++;
        else
            e++;
    }
    ll ans=1ll*pow(1ll*3,1ll*n)-pow(1ll*2,1ll*e);
    cout<<ans<<endl;
    return 0;
}