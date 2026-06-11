#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int x;
   if((a+b+c)%2 && (3*max({a,b,c}))%2 || (a+b+c)%2==0 && 3*max({a,b,c})%2==0)
   x=max({a,b,c});
   else
   x=max({a,b,c})+1;
  cout<<(3*x-(a+b+c))/2<<endl;
}