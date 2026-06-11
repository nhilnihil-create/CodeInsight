#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i,j;
    cin>>n>>x;
    int ara[n+1];
    ara[0]=x;
    for(i=1;i<=n;i++)
        cin>>ara[i];
    sort(ara,ara+n+1);
    int bra[n];
    for(i=1;i<=n;i++)
    {
        bra[i-1]=ara[i]-ara[i-1];
    }
    sort(bra,bra+n);
    for(i=bra[0];i>=1;i--)
    {
        int p=1;
        for(j=0;j<n;j++)
        {
            if(bra[j]%i !=0)
            {
                p=0;
                break;
            }
        }
        if(p==1)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
