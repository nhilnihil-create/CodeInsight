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
#include <bitset>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

bool is_prime(ll N){
  if (N == 1) return false;
  for (ll i = 2; i * i <= N; ++i){
    if (N % i == 0) return false;
  }
  return true;
}

int main(){
  int N; cin >> N;
  vector<int> prime;
  for (int i = 1; i <= 55555; ++i){
    if (is_prime(i) && i % 5 == 1) prime.push_back(i);
  }
  rep(i, N) cout << prime[i] << " ";
  cout << endl;
}
