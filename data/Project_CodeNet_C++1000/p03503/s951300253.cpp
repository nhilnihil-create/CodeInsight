#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
  int N;
  cin >> N;
  vi F(N, 0);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 10; j++){
      int f;
      cin >> f;
      if(f==1) F.at(i) |= (1<<j);
    }
  }
  vvll P(N, vll(11));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 11; j++){
      cin >> P.at(i).at(j);
    }
  }

  ll result = -1 * INF;
  for(int tmp = 1; tmp < (1<<10); tmp++){
    ll sum = 0;
    for(int i = 0; i < N; i++){
      int bit = tmp & F.at(i);
      int num = __builtin_popcount(bit);
      sum += P.at(i).at(num);
    }
    chmax(result, sum);
  }
  cout << result << endl;
}