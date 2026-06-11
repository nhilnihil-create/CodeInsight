#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n,m;
  cin >> n >> m;

  string s,t;
  cin >> s >> t;

  ll ans = lcm(n,m);
  ll s_step=ans/n, t_step=ans/m;

  ll j = min(n,m);
  rep(i,j){
    if(t_step*i>=n||s_step*i>=m) break;
    if(s.at(t_step*i)!=t.at(s_step*i)) ans = -1;
  }
  
  cout << ans;
}