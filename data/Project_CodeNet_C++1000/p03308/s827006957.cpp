#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int N;
  cin >> N;
  
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  
  int max = 0;
  int min = 1000000000;

  for (int i = 0; i < N; i++) {
    if (vec.at(i) > max) {
    	max = vec.at(i);
    }
    if (vec.at(i) < min) {
    	min = vec.at(i);
    }
  }
  
  cout << max - min << endl;
  
  return 0;
}