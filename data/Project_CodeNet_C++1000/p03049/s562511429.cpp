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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0; i<N; i++){
    cin >> S[i];
  }
  int ans = 0;
  int A=0,B=0,AB=0;

  for(int i=0; i<N; i++){
    for(int j=0; j<S[i].size()-1; j++){
      if(S[i].substr(j,2) == "AB") ans++;
    }
    if(S[i][0] == 'B' && S[i][S[i].size()-1] == 'A'){
      AB++;
    }else if(S[i][0] == 'B'){
      B++;
    }else if(S[i][S[i].size()-1] == 'A'){
      A++;
    } 
  }
  if(AB){
    ans += AB-1;
    if(A){
      ans++;
      A--;
    }
    if(B){
      ans++;
      B--;
    }
  }
  ans += min(A,B);
  cout << ans << endl;
  return 0;
}
