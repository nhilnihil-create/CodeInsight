#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int64_t> vector(87);
  vector.at(0) = 2;
  vector.at(1) = 1; 

  for(int i = 0; i < 85; i++){
      vector.at(i+2) = vector.at(i) + vector.at(i+1);
  } 

  int N;
  cin >> N;

  cout << vector.at(N) << endl;
}
