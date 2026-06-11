#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,t;
  ll a,b,c,d=0,i,k=0;
    cin>>a;
for(i=1;i<=a;i++)
{
cin>>b;d=max(d,b);
    k+=b;}
k-=d;
k+=(d/2);
cout<<k<<endl;
}