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
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

int main(){
  ll N, M;
  cin >> N >> M;
  priority_queue<Pll, vector<Pll>, greater<Pll>> que;
  for(int i = 0; i < M; i++){
    ll a, b;
    cin >> a >> b;
    que.push(Pll(a, b-1));
  }
  ll ans = 0;
  ll left = -1;
  ll right = INF;
  while(!que.empty()){
    ll a = que.top().first, b = que.top().second;
    que.pop();
    chmax(left, a);
    chmin(right, b);
    if(right < left){
      ans++;
      left = a;
      right = b;
    }
  }
  ans++;
  cout << ans << endl;
}