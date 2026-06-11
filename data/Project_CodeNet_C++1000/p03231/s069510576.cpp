#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; using ll=long long; const int INF=1e9+7; using P=pair<int,int>;
const int mx = 2e5;

ll gcd(ll a, ll b) {if (b==0) return a; else return gcd(b, a%b);}
int main() {
  ll n,m; cin>>n>>m;
  string s,t; cin>>s>>t;
  ll an=n*m/gcd(n,m);
  ll a=an/n, b=an/m;

  for(int i=0;i<n;i++) {
    if (a*i%b) continue;
    if (s[i] != t[a*i/b]) {
      an=-1; break;
    }
  }
  cout<<an<<endl;
}