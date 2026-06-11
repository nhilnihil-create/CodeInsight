#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
ll f(ll n){
  ll ans = 0;
  rep(i,50){
    ll tmp = pow(2,i),cnt = 0;
    if((n / tmp) % 2 == 0){
      cnt = (n / tmp) / 2 * tmp;
      if(cnt % 2 != 0)ans += pow(2,i);
    }
    else{
      cnt = (n / tmp) / 2 * tmp + (n % tmp);
      if(cnt % 2 != 0)ans += pow(2,i);
    }
  }
  return ans;
} 
int main(){
  ll a,b;
  cin >> a >> b;
  a = max(a - 1,(ll)0);
  cout << (f(a + 1) ^ f(b + 1)) << endl;
  return 0;
}
