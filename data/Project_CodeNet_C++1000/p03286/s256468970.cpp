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
  stack<int> s;
  if(N == 0){
    cout << 0 << endl;
    return 0;
  }
  while(N != 0){
    if(N < 0){
      s.push(N - (N-1)/(-2) * (-2));
      N = (N-1)/(-2);
    }
    else{
      s.push(N - N/(-2) * (-2));
      N /= (-2);
    }
  }
  while(!s.empty()){
    int x;
    x = s.top(); s.pop();
    cout << x;
  }
  cout << endl;
}