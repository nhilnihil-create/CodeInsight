#include<bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
   lli a,b;
   cin>>a>>b;
   if(abs(a-b) >=2)
   {
       cout<<max(a,b) +max(a,b)-1;
   }
   else
    cout<<a+b;


    return 0;
}
