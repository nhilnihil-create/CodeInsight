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
#define MOD 1000000007LL

ll ncr(ll n, ll r){
  if(n < r) return 0;
  if(r > n-r) r = n-r;

  ll a = 1, b = 1;
  for(int i = 0; i < r; i++){
    a *= (n - i);
  }
  for(int i = 0; i < r; i++){
    b *= (i + 1);
  }
  return a/b;
}

int main(){
  int N;
  cin >> N;
  vi prime(100, 0);
  for(int i = 2; i <= N; i++){
    int NN = i;
    for(int j = 2; j*j <= NN; j++){
      int counter = 0;
      while(NN % j == 0){
        counter++;
        NN /= j;
      }
      prime.at(j) += counter;
    }
    if(NN != 1) prime.at(NN)++;
  }
  vi box(0);
  for(int i = 0; i < 100; i++){
    if(prime.at(i) != 0) box.push_back(prime.at(i));
  }
  sort(ALL(box));
  int ans = 0;
  //75 = 3 * 5 * 5 = 15 * 5 = 3 * 25 = 75
  int two = distance(lower_bound(ALL(box), 2), box.end());
  int four = distance(lower_bound(ALL(box), 4), box.end());
  int fourteen = distance(lower_bound(ALL(box), 14), box.end());
  int twefour = distance(lower_bound(ALL(box), 24), box.end());
  int sevfour = distance(lower_bound(ALL(box), 74), box.end());
  ans += ncr(four, 2) * ncr(two-2, 1);
  ans += fourteen * (four-1);
  ans += twefour * (two-1);
  ans += sevfour;
  cout << ans << endl;
}