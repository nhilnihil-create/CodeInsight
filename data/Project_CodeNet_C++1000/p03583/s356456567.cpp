#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

int main(){
  ll N;
  cin >> N;
  for(ll h = 1; h <= 3500; h++){
    for(ll n = 1; n <= 3500; n++){
      ll x = 4LL*h*n - N*n - N*h;
      if(4LL*h*n - N*n - N*h == 0) continue;
      ll y = N*h*n;
      if(y/x > 0 && y % x == 0LL){
        cout << h << ' ' << n << ' ' << y/x << endl;
        return 0;
      }
    }
  }
}