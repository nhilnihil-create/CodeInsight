#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int MAX = 100000;
long long a[MAX],b[MAX],c[MAX], dp_a[MAX], dp_b[MAX], dp_c[MAX];

void solve() {
  int N;
  int lastE; 
  long long value=-INF;
  cin >> N ;
  for(int i=0;i<N;i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  for(int i=0;i<MAX;i++){
    dp_a[i] = -INF;
    dp_b[i] = -INF;
    dp_c[i] = -INF;
  }
  dp_a[0] = a[0];
  dp_b[0] = b[0];
  dp_c[0] = c[0];
  for(int i=0; i<N;i++){
    chmax(dp_b[i+1], dp_a[i]+b[i+1]);
    chmax(dp_c[i+1], dp_a[i]+c[i+1]);
    chmax(dp_a[i+1], dp_b[i]+a[i+1]);
    chmax(dp_c[i+1], dp_b[i]+c[i+1]);
    chmax(dp_b[i+1], dp_c[i]+b[i+1]);
    chmax(dp_a[i+1], dp_c[i]+a[i+1]);
  }
  cout << max({dp_a[N-1],dp_b[N-1],dp_c[N-1]}) <<endl;
  return;
}
 
int main() {
    solve();
    return 0;
}