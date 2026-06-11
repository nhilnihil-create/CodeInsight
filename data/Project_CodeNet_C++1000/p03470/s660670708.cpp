#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cnt = 0;
  cin >> N;
  
  vector<int> d(N);
  for(int i = 0; i < N; i++) {
    cin >> d.at(i);
  }
  
  sort(d.begin(), d.end());
  for(int i = 0; i < N-1; i++) {
    if(d.at(i) == d.at(i+1)) {
      d.at(i) = 0;
    }
  }
  
  for(int i = 0; i < N; i++) {
    if(d.at(i) != 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
}