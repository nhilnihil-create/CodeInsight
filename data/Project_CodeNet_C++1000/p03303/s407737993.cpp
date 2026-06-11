#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int w,i;
  string s;
  
  cin >> s >> w;
  i=0;
  while (i<s.size()){
    cout << s[i];
    i+=w;
  }
  cout << endl;
  
  return 0;
}