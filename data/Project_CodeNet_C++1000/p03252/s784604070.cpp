#include <bits/stdc++.h>
using namespace std;
int main(){
  string S, T;
  cin >> S >> T;
  unordered_map<char, char> mp;
  for(int i = 0; i < 26; i++) {
    mp[i + 97] = ' ';
  }
  for(int i = 0; i < (int) S.size(); i++) {
    if(mp[S.at(i)] == ' ' || mp[S.at(i)] == T.at(i)) {
      mp[S.at(i)] = T.at(i);
    }
    else{
      cout << "No" <<endl;
      return 0;
    }
  }
  for(int i = 0; i < 26; i++) {
    mp[i + 97] = ' ';
  }
  for(int i = 0; i < (int) S.size(); i++) {
    if(mp[T.at(i)] == ' ' || mp[T.at(i)] == S.at(i)) {
      mp[T.at(i)] = S.at(i);
    }
    else{
      cout << "No" <<endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}