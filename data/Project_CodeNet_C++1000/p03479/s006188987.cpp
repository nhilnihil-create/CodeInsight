#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int l=0,r=0,ans=0;
    cin>>l;
    cin>>r;

    while(l<=r)
    {
        l*=2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
