#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) =='x') ans++;
  }
  if(ans >= 8)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}