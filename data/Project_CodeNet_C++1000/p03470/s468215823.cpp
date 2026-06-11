#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> d(N);
  for (int i=0; i<N; i++) {
    cin >> d.at(i);
  }
  
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int tmp=d.at(0), cnt=1;
  for (int i=0; i<N; i++) {
    if (tmp>d.at(i)) {
      tmp = d.at(i);
      cnt++;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}
