#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());
//set_intersection(x, x+7, y, y+6, back_inserter(v));
//set_union(x, x+7, y, y+6, back_inserter(v));
//set_difference(x, x+7, y, y+6, back_inserter(v));

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

bool isPrime(int n){
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2==0) return false;

  for(int i=3;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  ll d,g;
  cin >> d >> g;
  vector<ll>P(d),C(d);
  for(int i=0;i<d;i++) cin >> P[i] >> C[i];
  ll ans = INF;
  for(int bit=0;bit<(1<<d);bit++){
    ll sum = 0;
    ll cnt = 0;
    for(int i=0;i<d;i++){
      if(bit & (1<<i)){
        sum += 100*(i+1)*P[i] + C[i];
        cnt += P[i];
      }
    }
    if(sum>=g) ans = min(ans,cnt);
    else{
      for(int i=d-1;i>=0;i--){
        if(bit & (1<<i)) continue;
        for(int j=0;j<P[i];j++){
          if(sum >=g) break;
          sum += 100 * (i+1);
          cnt++;
        }
      }
      ans = min(ans,cnt);
    }
  }
  cout<<  ans <<endl;
}
