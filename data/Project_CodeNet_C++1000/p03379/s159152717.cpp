#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  vector<int> sortedVec = vec;
  
  sort(sortedVec.begin(), sortedVec.end());
  
  int leftSide = sortedVec.at(vec.size() / 2 - 1);
  
  int rightSide = sortedVec.at(vec.size() / 2);
  
  for (int i = 0; i < N; i++) {
    
    int tmp = vec[i];
    
    if (tmp <= leftSide) cout << rightSide << endl;
    
    else cout << leftSide << endl;
    
  }
  
}