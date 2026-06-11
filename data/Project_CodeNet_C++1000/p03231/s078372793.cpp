#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main() {
 ll n,m;
  bool flag=true;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  
  r(i,gcd(n,m)){
    if(s[i*(n/gcd(n,m))]!=t[i*(m/gcd(n,m))])flag=false;
  }
  
  if(flag)cout<<lcm(n,m)<<endl;
  else cout<<-1<<endl;
}
