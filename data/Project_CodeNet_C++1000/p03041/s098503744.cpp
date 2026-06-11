#include <iostream>
using namespace std;
int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  s[k-1] += ' ';
  cout << s << "\n";
  return 0;
}