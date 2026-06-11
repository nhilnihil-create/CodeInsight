#include<iostream>
using namespace std;

int main() {
  int lose=0;
  string s;
  cin >> s;
  for(char c:s){
    if(c=='x') lose++;
  }
  if(lose<=7) cout << "YES";
  else cout << "NO";
  return 0;
}