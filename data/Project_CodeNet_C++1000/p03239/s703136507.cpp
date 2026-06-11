#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,t;
    ll a,b,c,d,e,i,j,k=99999999,l=0;
    cin>>a>>b;
  for(i=1;i<=a;i++)
  {
   cin>>c>>d;
   if(d<=b)
        {l=1;
        if(c<k){k=c;e=i;}}
  }
    if(l==0)cout<<"TLE\n";
 else cout<<k<<endl;
 }