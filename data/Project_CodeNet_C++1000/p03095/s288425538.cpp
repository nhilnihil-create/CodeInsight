#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int>a(26);
  for(int i=0;i<s.length();i++)
  {
    a[s[i]-'a']++;
  }
  mint ans=1;
  for(auto y:a)ans=ans*(y+1);
  ans-=1;
  cout<<ans.x<<endl;
  return 0;
}