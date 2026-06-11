  #include <bits/stdc++.h>
  using namespace std;

  const int MOD = 1000000007;
  const double PI = acos(-1); 

  //long long
  using ll = long long;

  //出力系
  #define print(x) cout << x << endl
  #define yes cout << "Yes" << endl
  #define YES cout << "YES" << endl
  #define no cout << "No" << endl
  #define NO cout << "NO" << endl
  
  // begin() end()
  #define all(x) (x).begin(),(x).end()

  //for
  #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

  //最大公約数（ll）
  ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x;}

  //素因数分解
  vector<pair<ll, int>>factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
      if(n % i) continue;
      res.emplace_back(i, 0);
      while(n % i == 0){
        n /= i;
        res.back().second++;
      }
    }
  if(n != 1) res.emplace_back(n, 1);
  return res;
  }



  //二分探索(最小値を出す問題は疑う)
  bool f(ll K){

  }

  ll binary_search(ll ok, ll ng){
    while(abs(ok - ng) > 1){
      ll mid = (ok + ng) / 2;
      if(f(mid)) ok = mid;
      else ng = mid;
    }
    return ok;
  }



int main(){

  vector<int>a(6);
  REP(i, 3){
    int x, y;
    cin >> x >> y;
    a.at(x)++;
    a.at(y)++;
  }

  int cnt = 0;
  REP(i, 6){
    if(a.at(i) == 2) cnt++;
  }

  if(cnt == 2) YES;
  else NO;
}