#include <bits/stdc++.h>
using namespace std;

int d[13];
int da[13],db[13];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool three=false;

    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int id;cin>>id;
        d[id]++;
        if(d[id]>=3)three=true;
    }

    if(three||d[0]>0||d[12]==2){cout<<0<<"\n";return 0;}

    int ans=24;
    da[0]=1;db[0]=1;
    int am=0,bm=0;
    for(int i=1;i<=11;i++)
    {
        if(d[i]==2)
        {
            da[i]=1;db[i]=1;
            ans=min(ans,min(i,24-i*2));
        }
        else if(d[i]==1)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(db[j]==1)
                {
                    da[i]=1;
                    for(;j>=0;j--)if(da[j]==1){ans=min(ans,i-j);break;}
                    am=i;
                    break;
                }
                if(da[j]==1)
                {
                    db[i]=1;
                    for(;j>=0;j--)if(db[j]==1){ans=min(ans,i-j);break;}
                    bm=i;
                    break;
                }
            }
        }
    }
    if(d[12]==1)
    {
        da[12]=1;db[12]=1;
        ans=min(ans,12-max(am,bm));
    }
    else ans=min(ans,24-am-bm);

    cout<<ans<<"\n";

    return 0;
}
