#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a[3],z,z1;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if((a[1]%2!=0&&a[0]%2!=0)||(a[1]%2==0&&a[0]%2==0))
    {
        z=(a[1]-a[0])/2;
        cout<<z+a[2]-a[1]<<endl;
    }
    else if((a[1]%2!=0&&a[0]%2==0)||(a[1]%2==0&&a[0]%2!=0))
    {
        z=(a[2]-a[1])/2;
        z1=(ceil)(a[2]-a[0])/2;
        cout<<z+z1+2<<endl;
    }
    return 0;
}
