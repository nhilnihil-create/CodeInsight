#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans=0;
    cin>>n;
    if(n%2==0)
    {
        cout<<n<<endl;
    }
    else
    {
        ans=n*2;
        cout<<ans<<endl;
    }
    return 0;
}