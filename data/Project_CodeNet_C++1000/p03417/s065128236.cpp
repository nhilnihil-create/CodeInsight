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

ll N, M;
vi dx = {1, 1, 1, 0, 0, -1, -1, -1};
vi dy = {1, 0, -1, 1, -1, 1, 0, -1};
ll func(int y, int x){
  int counter = 0;
  for(int i = 0; i < 8; i++){
      int yy = y + dy.at(i);
      int xx = x + dx.at(i);
      if(xx >= 0 && xx < M && yy >= 0 && yy < N) counter++;
  }
  if(counter % 2 == 0) return 1LL;
  else return 0LL;
}

int main(){
  cin >> N >> M;
  ll ans = func(0, 0);
  if(M >= 2){
    ans += func(0, M-1);
    if(M > 2){
      ans += func(0, 1) * (M - 2);
    }
  }
  if(N >= 2){
    ans *= 2;
    if(N > 2){
      if(M>=2)ans += 2 * func(1, 0) * (N - 2);
      else ans += func(1, 0) * (N - 2LL);
    }
  }
  if(N > 2 && M > 2) ans += (N-2LL) * (M-2LL);
  cout << ans << endl;
}