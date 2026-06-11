#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;
template<typename T>
map<T, ll> prime_factorize(T x, map<T,ll> m){

  while(x%2==0){
    x/=2;
    m[2]++;
  }

  for(ll i=3;i*i<=x;i+=2){
    while(x%i==0){
      x/=i;
      m[i]++;
    }
  }
  if(x!=1) m[x]++;
  return m;
}


int main(){
  cout << setprecision(10);
  map<ll,ll> m;
  ll N;
  cin >> N;
  for(ll i = 2; i <= N; i++){
    m = prime_factorize(i, m);
  }
  int over_75 = 0;
  int over_25 = 0;
  int over_15 = 0;
  int over_5 = 0;
  int over_3 = 0;

  for(auto x: m){
    cerr << x.first << " " << x.second << endl;
    if(x.second >= 74){
      over_75++;
    }
    if(x.second >= 24){
      over_25++;
    }
    if(x.second >= 14){
      over_15++;
    }
    if(x.second >= 4){
      over_5++;
    }
    if(x.second >= 2){
      over_3++;
    }
  }
  ll ans = 0;
  // 75
  ans += over_75;
  // 25 * 3
  ans += over_25 * (over_3 - 1);
  // 15 * 5 
  ans += over_15 * (over_5 - 1);
  // 5 * 5 * 3
  ans += over_5 * (over_5 - 1) / 2 * (over_3 - 2);

  cout << ans << endl;
  
}
