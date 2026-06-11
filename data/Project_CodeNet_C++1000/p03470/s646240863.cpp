#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  
  for (int i=0; i<N; i++) {
    cin >> H.at(i);
  }
  
  sort(H.begin(),H.end());
  reverse(H.begin(),H.end());
  
  int sum=1;
  
  for (int i=0; i<N-1; i++) {
    if (H.at(i)-H.at(i+1) > 0) {
      sum++;
    }
  }
  
  cout << sum << endl;
}