#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < s.length(); i++){
    char num = s[i];
  	ans += num - 48;
  }
  cout << (atoi(s.c_str()) % ans == 0 ? "Yes" : "No") << endl;
}