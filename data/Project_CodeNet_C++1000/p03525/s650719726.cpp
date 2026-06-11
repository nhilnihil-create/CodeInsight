#include <bits/stdc++.h>
using namespace std;
int n;
int d[55];
int dd[55];
int num[50];
int ans;
int main()
{
    num[0]=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>d[i];
            num[d[i]]++;
        }
    for(int i=0;i<=11;i++)
    {
        if(num[i]>2)
        {
            cout<<"0\n";
            return 0;
        }
    }
    if(num[12]>1)
    {
        cout<<"0\n";
        return 0;
    }
    if(n>=24)
        cout<<"0\n";
    else if(n==23)
    {
        cout<<"1\n";
    }
    else
    {
        int xx=1;
        xx<<=(n+1);
        xx--;
        //cout<<xx<<endl;
        for(int i=0;i<=xx;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i&(1<<j))
                    dd[j]=d[j];
                else
                    dd[j]=24-d[j];
                if(dd[j]==24)
                    dd[j]=0;
            }
//            for(int j=0;j<=n;j++)
//                cout<<dd[j]<<" ";
//            cout<<endl;
            sort(dd,dd+1+n);
            int minn=100;
            for(int j=n;j>0;j--)
            {
                if(dd[j]-dd[j-1]<minn)
                    minn=dd[j]-dd[j-1];
            }
            if(24-dd[n]<minn)
                minn=24-dd[n];
            ans=max(ans,minn);
        }
        cout<<ans<<endl;
    }
}
