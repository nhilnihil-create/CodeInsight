#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b;
    cin>>n>>a>>b;

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        int m=i;
        int sum=0;
        while(m/10)
        {
            sum+=m%10;
            m/=10;
        }
        sum+=m%10;

        if(a<=sum&&sum<=b)ans+=i;
    }

    cout<<ans<<"\n";

    return 0;
}
