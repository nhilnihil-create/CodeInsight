#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba") cout << "Yes" << "\
\n";
  else cout << "No" << "\n";
  return 0;
}