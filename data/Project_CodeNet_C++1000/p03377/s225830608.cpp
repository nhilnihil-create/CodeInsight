#include <bits/stdc++.h>
using namespace std;
int pre[104];
int main()
{
       int a,b,x;
       cin>>a>>b>>x;
       if(x-a<=b && x>=a)
        cout<<"YES";
       else cout<<"NO";
    return 0;
   }