#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  string str; cin >> str;
  int size;
  size = str.size();
  
  //compute
  long long sum;
  sum = 0;
  vector<int> x(size+1);
  x[0] = 0;

  if(str.at(0) == 'B') {
     x[0] = 1;
  }

  for(int i = 1; i < size; i++) {
    if(str.at(i) == 'B') {
     x[i] = x[i - 1] + 1;
  }else if(str.at(i) == 'W'){
     x[i] = x[i - 1]; 
  }
  }


  for(int i = 1; i < size; i++) {
    if(str.at(i) == 'W') {
     sum += x[i-1];
  }
  }
 
  //output
  cout << sum << endl;
 
}
