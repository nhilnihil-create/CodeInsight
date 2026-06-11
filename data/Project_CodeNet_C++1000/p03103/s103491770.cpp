//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;


int main(){
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> p;
  ll a,b;
  rep(i,n){
    cin >> a >> b;
    p.push_back(make_pair(a,b));
  }
  sort(p.begin(),p.end());
  ll memo = 0;
  ll ans = 0;
  rep(i,n){
    if(memo + p[i].second < m){
      ans += p[i].first*p[i].second;
      memo += p[i].second;
    }else{
      ans += p[i].first*(m-memo);
      break;
    }
  }
  printf("%lld\n", ans);
    return 0;
}
