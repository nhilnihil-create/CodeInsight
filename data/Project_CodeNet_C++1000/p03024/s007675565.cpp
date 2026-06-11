#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  int n = (int)s.size();
  int cnt = 0;
  for(int i = 0; i < n; ++i)cnt += s[i] == 'o';
  cout << (cnt + 15 - n >= 8 ? "YES" : "NO") << endl;
  return 0;
}