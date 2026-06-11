#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

vector<ll> enum_divisors(ll N){
  vector<ll> res;
  for (ll i = 1; i * i <= N; ++i){
    if (N % i == 0) {
      res.push_back(i);
      //重複しない時
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main(){
  int A, B, K; cin >> A >> B >> K;
  int now = 0;
  for (int i = 100; i >= 0; --i){
    if (A % i == 0 && B % i == 0){
      now++;
    }
    if (now == K){cout << i << endl; return 0;}
  }
}
