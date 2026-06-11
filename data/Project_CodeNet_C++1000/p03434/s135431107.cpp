#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  
  int sa=0,sb=0;
  
  for (int i=0; i<N; i++) {
    if (i%2==0) {
      sa += A.at(i);
    }
    else {
      sb += A.at(i);
    }
  }
  
  cout << sa-sb << endl;
}