#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
//  cout << N <<endl;
  vector<int> a(N);
  for(int i=0; i<N; ++i) {
    cin >> a.at(i);
//    cout << a.at(i) << endl;
  }

/*  for(int i=0; i<N; ++i) {
    cout << a.at(i) << ' ';
  }*/
  
  sort(a.begin(), a.end());
  
/*  cout <<endl;
  for(int i=0; i<N; ++i) {
    cout << a.at(i) << ' ';
  }*/

  int A=0, B=0;
  for(int i=0; i<N; ++i) {
    if (i%2 == 0) {
      A += a.at(N-i-1);
    } else {
      B += a.at(N-i-1);
    }
  }
  
  int result = A - B;
  
  cout << result <<endl;
  
  return 0;
}