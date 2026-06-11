#include<bits/stdc++.h>
using namespace std;

#define bolt ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define endl "\n"

typedef long long ll;
typedef long double ld;

const ld pi=3.1415926535897932384626433;
const int mod = 1000000007;
const ll inf=3e18;
bool check(ll i)
{
   set <char> d;
   string s=to_string(i);
   for (ll k=0;k<s.size();k++)
   {
      d.insert(s[k]);
   }
   if (d.size()==1)
      return true;
   return false;
}
int main()
{
   bolt;
   ll n;
   cin>>n;
   for (ll i=n;i<=999;i++)
   {
      if (check(i))
         return cout<<i, 0;
   }
}
