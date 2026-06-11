#include <bits/stdc++.h>
#include<set>
#include<vector>
using namespace std;

int main() {
    int k,b,i,j,l,count,v,m,n;
    //cin>>k;
    cin>>n>>m;
    int a[m];
    for(i=0;i<m;i++)
    {
        a[i]=0;
    }
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>v;
            
          for(l=1;l<=m;l++)
          {
             if(v==l)
             {
                 a[l-1]+=1;
                 //cout<<a[l-1]<<endl;
                 break;
             }
          }
        }
    }
    count=0;
    for(i=0;i<m;i++)
    {
        if(a[i]==n)
        {
            count++;
        }
    }
    cout<<count<<endl;
}
