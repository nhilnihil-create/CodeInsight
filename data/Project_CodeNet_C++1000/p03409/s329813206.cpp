#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<pair<int, int> > R(N);
  vector<pair<int, int> > B(N);
  
  int a, b;
  for ( int i = 0; i < N; i++ ) {
    cin >> a >> b;
    R[i] = make_pair(a, b);     //赤い点
  }
  
  int c, d;
  for ( int i = 0; i < N; i++ ) {
    cin >> c >> d;
    B[i] = make_pair(c, d);     //青い点
  }
  sort(B.begin(), B.end());
  
  int ans = 0;
  for ( int i = 0; i < N; i++ ) {
    int max = -1;
    int k = 0;
    for ( int j = 0; j < R.size(); j++ ) {
      if ( R[j].first < B[i].first && R[j].second < B[i].second ) {
        if ( R[j].second > max ) {
          max = R[j].second;
          k = j;
        }
      }
    }
    if ( max != -1 ) {
      R.erase(R.begin() + k);
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
  
}