#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 510000;
const int INF = 1e9;
const double pi=acos(-1);

int main(){
  int n;
  cin >> n;
  vector<ll>a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  vector<ll>gap;
  ll sum = 0;
  int num = 0;
  
  rep(i,n){
    ll diff = b[i] - a[i];
    if(diff>0){
      num++;
      sum += diff;
    }
    else gap.push_back(-diff);
  }
  
  if(num==0){
    cout << 0 << endl;
    return 0;
  }
  sort(gap.begin(),gap.end(),greater<ll>());
  
  ll plus=0;
  int res = num;
  rep(i,gap.size()){
    plus+=gap[i];
    res++;
    if(plus>=sum){
      break;
    }
  }
  if(plus>=sum) cout << res << endl;
  else cout << -1 << endl;
  return 0;
}
