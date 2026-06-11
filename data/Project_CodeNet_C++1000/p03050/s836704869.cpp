#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

vector<pair<ll,ll>> primefactorize(ll n){
  vector<pair<ll,ll>> res;
  for(ll i = 2;i*i <= n;i++){
    if(n%i)continue;
    res.push_back(make_pair(i,0));
    while(!(n%i)){
      res.back().second++;
      n /= i;
    }
  }
  if(n != 1)res.push_back(make_pair(n,1));
  return res;
}

int main(){
  
  ll n;
  cin >> n;
  ll res = 0;
  for(ll i = 2;i*i < n;i++){
    if(n%i)continue;
    if((n/(i-1)) == (n%(i-1)))res += (i-1);
    if((n/(n/i-1)) == (n%(n/i-1)))res += (n/i-1);
  }
  if(n != 2)res += n-1;
  cout << res << endl;
  





  return 0;
}