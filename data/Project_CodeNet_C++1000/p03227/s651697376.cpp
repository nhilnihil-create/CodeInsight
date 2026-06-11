#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int i;
  string s;
  
  cin >> s;
  
  if (s.size()==2) cout << s << endl;
  else{
    for (i=0;i<3;i++) cout << s[s.size()-i-1];
    cout << endl;
  }
  
  return 0;
}