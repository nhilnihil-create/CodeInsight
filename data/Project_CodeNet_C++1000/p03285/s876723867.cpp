#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N][N];
  int main()
{  
    int t,n,m;
    cin>>n;
    int flag=0;
    for(int i=0;i<=n/4;i++)
    {
        m=n;
        m-=4*i;
        if(!m)flag=1;
        for(int j=0;j<=m/7;j++)
        {
            t=m;
            t-=7*j;
            if(!t)flag=1;
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    
        
    return 0;
}