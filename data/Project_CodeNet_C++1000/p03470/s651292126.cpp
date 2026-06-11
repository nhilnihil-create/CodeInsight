#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
//  cout << N <<endl;
  vector<int> d(N);
  for(int i=0; i<N; ++i) {
    cin >> d.at(i);
//    cout << d.at(i) << endl;
  }

  sort(d.begin(), d.end());
  
/*  for(int i=0; i<N; ++i) {
    cout << d.at(i) << ' ';
  }*/

  int tmp = 0;
  int result = 0;
  for(int i=0; i<N; ++i) {
    if (tmp < d.at(i)) {
      tmp = d.at(i);
      result++;
    }
  }

  cout << result <<endl;
  
  return 0;
}