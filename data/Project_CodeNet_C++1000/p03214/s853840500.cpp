#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  int sum = 0;  
  for ( int i = 0; i < N; i++ ) {
    cin >> a[i];
    sum += a[i];
  }

  int mi = 1e9, id;
  for ( int i = 0; i < N; i++ ) {
    if ( mi > abs(sum - a[i]*N) ) {
      mi = abs(sum - a[i]*N);
      id = i;
    }
  }

  cout << id << endl;

  return 0;
}
