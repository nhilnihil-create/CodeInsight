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
  ll N, C;
  cin >> N >> C;
  vll x(N), y(N), v(N);
  vll vx(N+1, 0), vy(N+1, 0);
  for(int i = 0; i < N; i++){
    cin >> x.at(i) >> v.at(i);
    y.at(i) = C - x.at(i);
    vx.at(i+1) = vx.at(i) + v.at(i);
  }
  sort(ALL(y));
  for(int i = 0; i < N; i++){
    vy.at(i+1) = vy.at(i) + v.at(N-1-i);
  }

  vll xpoint(N+1, 0), ypoint(N+1, 0); //時計、反時計回りにi回進んだときのポイント
  vll xmax(N+1, 0), ymax(N+1, 0); //i回進むまでの最高ポイント
  for(int i = 0; i < N; i++){
    xpoint.at(i+1) = vx.at(i+1) - x.at(i);
    ypoint.at(i+1) = vy.at(i+1) - y.at(i);
    xmax.at(i+1) = max(xmax.at(i), xpoint.at(i+1));
    ymax.at(i+1) = max(ymax.at(i), ypoint.at(i+1));
  }
  
  ll ans = 0;
  for(int i = 0; i < N; i++){ //i個反時計回りのあと時計回り
    ll point = 0;
    if(i != 0){
      if(y.at(i-1) >= C/2) break;//半分以上遡るのは無駄
      point += vy.at(i) - 2 * y.at(i-1);
    }
    chmax(ans, point + xmax.at(N-i));
  }

  for(int i = 0; i < N; i++){
    ll point = 0;
    if(i != 0){
      if(x.at(i-1) >= C/2) break;
      point += vx.at(i) - 2 * x.at(i-1);
    }
    chmax(ans, point + ymax.at(N-i));
  }

  cout << ans << endl;
}