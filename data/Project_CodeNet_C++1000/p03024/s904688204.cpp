#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int count = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == 'x')count++;
  }
  if(count < 8)cout << "YES" << endl;
  else cout << "NO" << endl;
}
