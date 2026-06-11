#include <bits/stdc++.h>
using namespace std;

int h[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)cin>>h[i];

    int ans=0;

    for(;;)
    {
        int cnt=0;
        bool zero=true;
        for(int i=0;i<n;i++)
        {
            if(zero)
            {
                if(h[i]>0)
                {
                    cnt++;
                    zero=false;
                }
            }
            else
            {
                if(h[i]<=0)zero=true;
            }    
        }
        if(cnt==0)break;
        ans+=cnt;
        for(int i=0;i<n;i++)h[i]=max(h[i]-1,0);
    }

    cout<<ans<<"\n";

    return 0;
}
