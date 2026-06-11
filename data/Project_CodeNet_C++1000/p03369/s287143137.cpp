#include <bits/stdc++.h>
#include <iostream>
#include <boost/range/algorithm/count.hpp>
using namespace std;

int main(){
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.length(); i++){
    if (s.at(i) == 'o'){
      count++;
    }
  }
  cout << 700 + (100 * count) << endl;
}
