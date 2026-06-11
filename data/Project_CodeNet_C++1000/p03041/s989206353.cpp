#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
  ll n,k;
  cin>>n>>k;
  string s;
  --k;
  cin>>s;
  if(s[k]=='A')
  s[k]='a';
  else if(s[k]=='B')
  s[k]='b';
  else
  s[k]='c';
  cout<<s;}