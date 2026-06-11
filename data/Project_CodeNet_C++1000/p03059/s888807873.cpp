#include<bits/stdc++.h>
using namespace std;
int main()

{
    int x,b,t,c=0;
    cin>>x>>b>>t;
    for(int i=1;i<=t;i++)
    {
        if(i%x==0)
      c+=b;
    }
cout<<c;
}