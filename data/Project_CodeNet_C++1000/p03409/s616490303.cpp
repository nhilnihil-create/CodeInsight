#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


int main() {
  int n; cin >>n;
  vector<pair<int,int>> red(n), blue(n);
  rep(i, n) cin >>red[i].first >>red[i].second;
  rep(i, n) cin >>blue[i].first >>blue[i].second;
  
  // blueはx座標の小さい順、x座標が同じであればy座標の小さい順にソート
  sort(all(blue));

  // redはy座標の大きい順、y座標が同じであればx座標の小さい順にソート
  rep(i, n) swap(red[i].first, red[i].second);
  rep(i, n) red[i].first *= -1;
  sort(all(red));
  rep(i, n) red[i].first *= -1;
  rep(i, n) swap(red[i].first, red[i].second);

  // で、各blueについてgreedyにペアのredを決定していく
  vector<bool> redpair(n, false);
  // redpair[i] := red[i]がペアを形成しているかどうか
  rep(b, n){
    // blue[b]についてペアを探していく
    rep(r, n){
      if (redpair[r]) continue; // 既にペアを形成している
      if (red[r].second >= blue[b].second) continue; // y座標がblue以上である
      if (red[r].first < blue[b].first){
        // ペアを形成していないredのうち、y座標がblue未満でx座標もblue未満であればペア成立
        redpair[r] = true;
        break;
      }
    }
  }
  int res = 0;
  rep(i, n) res += redpair[i];
  cout <<res <<endl;
}
