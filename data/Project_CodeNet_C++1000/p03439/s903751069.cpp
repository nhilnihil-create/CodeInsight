#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
  int N; cin >> N;
  cout << 0 << endl;
  string front;
  cin >> front;
  if (front == "Vacant") return 0;

  string ans;
  int left = -1, right = N, mid;
  while (true) {
    mid = (left + right) / 2;
    cout << mid << endl;
    cin >> ans;
    if (ans == "Vacant") return 0;

    if (ans == front && mid % 2 == 0 || ans != front && mid % 2 == 1) {
      left = mid;
    }
    else right = mid;
  }


  return 0;
}