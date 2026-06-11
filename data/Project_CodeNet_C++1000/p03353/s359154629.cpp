#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  string s; cin >> s;
  int k; cin >> k;
  set<string> se;
  for(int i = 0; i < s.length(); i++){
    for(int j = 1; j <= min((int)s.length() - i, 5); j++){
      string str = s.substr(i, j);
      se.insert(str);
    }
  }
  int i = 0;
  for(auto itr = se.begin(); itr != se.end(); ++itr){
    if(i == k - 1) cout << *itr << endl;
    i++;
  }


  return;
}

/*void solve2(){
  string s; cin >> s;
  int k; cin >> k;
  char ch = 'a';
  for(int i = 0; i < s.length(); i++){
    if(s[i] == ch){
      for(int j = 1; j <= min(s.length() - i, 5); j++){
        string str = s.substr(i, j);
        se.insert(str);
      }
    }
  }
}*/
int main(){
  solve();
  //solve2();
  return 0;
}
