#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,E;
  cin >> A >> B >> C >> D >> E;
  
  int a,b,c,d,e;
  a = 10 - A % 10;
  b = 10 - B % 10;
  c = 10 - C % 10;
  d = 10 - D % 10;
  e = 10 - E % 10;
  
  vector<char> N(5);
  N.at(0) = a;
  N.at(1) = b;
  N.at(2) = c;
  N.at(3) = d;
  N.at(4) = e;
  
  for (int i = 0; i < 5; i++) {
    if (N.at(i) == 10){
      N.at(i) = 0;
    }
  }
  sort(N.begin(), N.end());
  int M = N.at(0) + N.at(1) + N.at(2) + N.at(3);
  
  cout << A + B + C + D + E + M << endl;
}
  
  