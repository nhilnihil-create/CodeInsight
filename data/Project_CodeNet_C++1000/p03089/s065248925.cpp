#include <bits/stdc++.h>
using namespace std;

int a[110],b[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>b[i];

    bool ans=true;

    for(int i=n-1;i>=0;i--)
    {
        int pos=i+1;
        for(int j=n-1;j>=0;j--)
        {
            if(b[j]==pos)
            {
                a[i]=b[j];
                b[j]=0;
                break;
            }
            else if(b[j]!=0)pos--;
        }
        if(pos==0){ans=false;break;}
    }

    if(ans)for(int i=0;i<n;i++)cout<<a[i]<<"\n";
    else cout<<-1<<"\n";

    return 0;
}
