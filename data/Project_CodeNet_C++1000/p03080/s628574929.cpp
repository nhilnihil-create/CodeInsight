#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  
  auto red = count(s.cbegin(), s.cend(), 'R');
  auto blue = count(s.cbegin(), s.cend(), 'B');
  
  if(red > blue) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
