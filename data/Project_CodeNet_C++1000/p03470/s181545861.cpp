//#include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> mochi(N);
  for(int i = 0; i < N; i++) {
    cin >> mochi[i];
  }
  
  sort(mochi.begin(), mochi.end());
  reverse(mochi.begin(), mochi.end());
  
  int count = 0;
  int prev = 999;
  for(int i = 0; i < N; i++) {
    if(mochi.at(i) < prev) {
      prev = mochi.at(i);
      count++;
    }
  }
  
  cout << count << endl;
}
