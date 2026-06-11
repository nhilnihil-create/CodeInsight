#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  
  vector<int> vec ={A+C,A+D,B+C,B+D};
  sort(vec.begin(),vec.end());
  
  cout << vec.at(0) << endl;
}
