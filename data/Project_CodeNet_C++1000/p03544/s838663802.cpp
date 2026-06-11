#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   ll cum[90]={0};
   cum[0]=2;
   cum[1]=1;
   for(ll i=2;i<=86;i++)
   {
       cum[i]=cum[i-1]+cum[i-2];
   }
   ll n;
   cin>>n;
   cout<<cum[n]<<endl;

}








