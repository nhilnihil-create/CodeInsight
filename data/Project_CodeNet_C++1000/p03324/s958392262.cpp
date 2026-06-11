#include <bits/stdc++.h>
using namespace std;

int main()
{
       int d,n;
       long long x=1;
       cin>>d>>n;

       for(int i=0;i<d;i++)
       x*=100;
       if(n!=100)
       cout<<n*x;
       else cout<<x*(n+1);

    return 0;
   }