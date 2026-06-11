#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N+1, vector<int>(3)); 
  vec.at(0).at(0) = 0;
  vec.at(0).at(1) = 0;
  vec.at(0).at(2) = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i+1).at(0) >> vec.at(i+1).at(1) >> vec.at(i+1).at(2);
  }
  
  bool can = true;
  int dist, time;
  for (int i = 0; i < N; i++) {
    dist = abs(vec.at(i + 1).at(1) - vec.at(i).at(1)) + abs(vec.at(i + 1).at(2) - vec.at(i).at(2));
    time = vec.at(i + 1).at(0) - vec.at(i).at(0);
    
    if (dist > time || (time - dist) % 2 != 0) {
      can = false;
    }   
  } 
  
  if (can) cout << "Yes";
  else cout << "No";
}
