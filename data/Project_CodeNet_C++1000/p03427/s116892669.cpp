#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  string str;
  cin >> num;
  int one = 0;
  int kurisage = 0;
  int other = 0;
  
  num++;
  str = to_string(num);
  int len = str.size();
  
  int cnt;
  
  one = stoi(str.substr(0,1)) - 1;
  other = (len - 1) * 9;
  cout << one + other;  
}
