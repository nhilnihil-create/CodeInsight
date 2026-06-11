#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
      ll n,k,ans=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        if(i-1<k)
            continue;
        ll pos=i-1;
        ll can=(i-k);
        ans+=(n/i)*can;
        ll rem=n%i;
        if(rem)
        {
            if(rem<k)
                continue;
            ans+=(rem-k+1);
            if(!k)
                ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
