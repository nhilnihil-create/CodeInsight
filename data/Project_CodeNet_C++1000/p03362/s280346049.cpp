#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;
bool is_prime(long long n){
    for(long long i = 2; i*i <= n ; i++){
        if(n%i == 0)return false;
    }
    return n != 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> res;
  for (int i = 2; i <= 55555; i++) {
    if (is_prime(i) && i % 5 == 1) {
      res.emplace_back(i);
    }
  }
  rep(i,n) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
} 