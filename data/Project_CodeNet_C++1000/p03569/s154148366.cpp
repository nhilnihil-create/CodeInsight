#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
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
// ----------------------------------------------------------------------------

int main(){
  string S;
  int N;
  cin >> S;
  N = S.size();
  int l=0,r=N-1;
  int cnt = 0;
  while(l < r){
    if(S[l]=='x' && S[r]!='x'){
      l++;
      cnt++;
      continue;
    }
    if(S[r]=='x' && S[l]!='x'){
      r--;
      cnt++;
      continue;
    }
    if(S[l] != S[r]){
      cout << -1 << endl;
      return 0;
    }
    l++;
    r--;
  }
  cout << cnt << endl;
  return 0;
}
