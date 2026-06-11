#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()

#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

int main()
{
  string s,ss;
  ll n,i=0,j=0;
  cin>>s; cin>>n;
  for(i=0;i<s.size();i+=n)
    cout<<s[i];

    return 0;
}
