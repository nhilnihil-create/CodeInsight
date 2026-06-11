#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int n,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i]-1;
    }
    cout<<ans<<endl;
    return 0;
}