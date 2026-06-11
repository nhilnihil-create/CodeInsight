#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for(int i = 0; i < N; i++) {
    cin >> d.at(i);
  }

  int count = 0;
  vector<int> flag(101, 0);
  for(int i = 0; i < N; i++) {
    flag.at(d.at(i)) = 1;
  }
  for(int i = 0; i < 101; i++) {
    if(flag.at(i) == 1) {
      count++;
    }
  }
  cout << count << endl;
  
  return 0;
}