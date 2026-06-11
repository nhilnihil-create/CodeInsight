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

int main(){
  int N, K;
  cin >> N >> K;
  ll result = 0;
  if(K % 2 == 0){
    set<int> s;
    for(int i = K/2; i <= N; i+= K){
      s.insert(i);      
    }
    ll num = s.size();
    result += num * num * num;
  }
  set<int> s;
  for(int i = K; i <= N; i+=K){
    s.insert(i);
  }
  ll num = s.size();
  result += num * num * num;
  cout << result << endl;
}