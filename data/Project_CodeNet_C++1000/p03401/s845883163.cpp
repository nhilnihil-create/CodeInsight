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
  vi A(N), dA(N, 0), sdA(N+1, 0);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    if(i == 0) dA.at(i) = abs(A.at(i));
    else{
      dA.at(i) = abs(A.at(i) - A.at(i-1));
    }
  }
  for(int i = 0; i < N; i++){
    sdA.at(i+1) = sdA.at(i) + dA.at(i);
  }
  
  //cout << sdA.at(N) - sdA.at(0) << endl;
  
  for(int i = 0; i < N; i++){
    int ans = 0;
    if(i != 0){
      ans += sdA.at(i) - sdA.at(0);
    }

    if(i != 0 && i != N-1){
      ans += abs(A.at(i+1) - A.at(i-1));
    }
    else if(i == 0) ans += abs(A.at(i+1));
    
    if(i != N-1){
      ans += sdA.at(N) - sdA.at(i+2);
      ans += abs(A.at(N-1));
    }
    else ans += abs(A.at(N-2));

    cout << ans << endl;

  } 
}