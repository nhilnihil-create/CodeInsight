#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >>b >>c;
  vector<int>s(3);
  s.at(0)=a;
  s.at(1)=b;
  s.at(2)=c;
  sort(s.begin(), s.end());
  cout << s.at(2)*10 + s.at(1) + s.at(0) <<endl;    
}
