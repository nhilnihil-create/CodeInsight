#include <bits/stdc++.h>
#include <iostream>
#include <boost/range/algorithm/count.hpp>
using namespace std;

int main(){
  string s;
  cin >> s;
  int count = boost::count(s, '1');
  cout << count << endl;
}
