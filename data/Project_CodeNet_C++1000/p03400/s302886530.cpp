#include <bits/stdc++.h>
using namespace std;
int main()
{
       int n,d,x,c=0,s;
       cin>>n>>d>>x;
       for(int i=0;i<n;i++){
        cin>>s;
        for(int j=1;j<=d;j++)
            if((s*j+1)<=d)
            c++;
       }
       cout<<c+n+x;
    return 0;
   }