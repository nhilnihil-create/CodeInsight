#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,k;
  string s;
  cin >> n >> k;
  cin >> s;
  s[k-1] += 'a'-'A';
  cout << s << endl;
  return 0;
}