#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,x,l,r;
   cin>>a>>b>>x;
   l=a,r=a+b-1;

   if(x>=l && x<=r)cout<<"YES\n";
   else cout<<"NO\n";

}
