#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll min=m;
    ll ans,i=0;
    while(true)
    {
        if((i+k-1)>=n)break;
        min=a[i+k-1]-a[i];
        if(min<ans)
            ans=min;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}