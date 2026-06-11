#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,b,g,f,w;
  f = 1;
  w = 1;
  cin >> N;
  b = N;
  vector<int> a(N + N);
  for(int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      g = a.at(j + f);
      if(a.at(i) == g) {
        b = b - 1;
        a.at(j + f) = 101 + w;
      }
      w++;
    }
    f++;
  }
  cout << b << endl;
      
       
}