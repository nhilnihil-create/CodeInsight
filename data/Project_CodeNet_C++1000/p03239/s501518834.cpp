#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n,T;
    cin>>n>>T;
    long long  m=INT_MAX;
    int  f=0;
    for(long long  i=0;i<n;i++)
    {
        long long  c,d;
        cin>>c>>d;
        if(d<=T)
        {
           m=min(m,c);
           f=1;
        }
    }
    if(f==0)
    {
        cout<<"TLE"<<endl;
    }
    else{
      cout<<m<<endl;  
    }
    
return 0;
}
