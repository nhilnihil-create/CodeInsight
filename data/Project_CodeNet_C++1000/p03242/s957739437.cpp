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

int main()
{
   bolt;
   string s;
   cin>>s;
   for (ll i=0;i<s.size();i++)
   {
      if (s[i]=='1')
         s[i]='9';
      else if (s[i]=='9')
         s[i]='1';
   }
   cout<<s;
}
