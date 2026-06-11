#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main(){
  string str; cin >> str;
  if(str.at(5)=='0' && str.at(6)=='1')  cout << "Heisei" << endl;
  else if(str.at(5)=='0' && str.at(6)=='2')  cout << "Heisei" << endl;
  else if(str.at(5)=='0' && str.at(6)=='3')  cout << "Heisei" << endl;
  else if(str.at(5)=='0' && str.at(6)=='4')  cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}