#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) cin >> d[i];
  sort(d.begin(), d.end());
  
  int count=1;
  
  rep(i, N-1) {
    if (d[i+1]-d[i]>0) count++;
  }
  cout << count << endl;
}
