//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int alice = 0;
  int bob = 0;
  for(int i = 0; i < vec.size(); i++) {
    if(i % 2 == 0) {
      alice += vec.at(i);
    } else {
      bob += vec.at(i);
    }
  }
  cout << alice - bob << endl;
}
