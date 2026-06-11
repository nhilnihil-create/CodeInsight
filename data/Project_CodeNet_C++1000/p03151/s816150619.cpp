#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};
 
// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ---------------------------------------------------------------------------
 
int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  ll sum_A=0,sum_B=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum_A += A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
    sum_B += B[i];
  }
  if(sum_A < sum_B){
    cout << -1 << endl;
    return 0;
  }
  int cnt = 0;
  priority_queue<int> que;
  ll sum = 0;
  for(int i=0; i<N; i++){
    if(A[i] < B[i]){
      cnt++;
      sum += B[i]-A[i];
    }else if(B[i] < A[i]){
      que.push(A[i]-B[i]);
    }
  }
  while(que.size()){
    if(sum<=0){
      cout << cnt << endl;
      return 0;
    }
    int d = que.top();
    que.pop();
    sum -= d;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}