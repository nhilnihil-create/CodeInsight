#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,minn;
    cin>>n;
    int ara[n];
    for(i=0; i<n; i++) cin>>ara[i];
    sort(ara,ara+n);
    int m=ara[0],ii=0,cnt=0,ind;
    while(1)
    {
        ind=ii,minn=m;
       for(i=0;i<n;i++)
       {
           if(i==ind) continue;
           if(ara[i])
           {
               ara[i]%=minn;
               if(ara[i]==0)
                cnt++;
               else if(ara[i]<m)
               {
                   m=ara[i];
                   ii=i;
               }
           }
       }
        if(cnt==(n-1))break;
    }
    cout<<m<<endl;
    return 0;
}
