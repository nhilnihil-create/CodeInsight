#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<int> ch_list(26, 0);
  for(char ch: s){
    ch_list[ch - 'a']++;
  }
  bool flag = true;
  for(int i = 0; i < 26; ++i){
    if(ch_list[i] > 0) continue;
    flag = false;
  }
  if(flag){
    flag = true;
    for(int i = 25; i >= 0; --i){
      if(s[25 - i] - 'a' == i) continue; 
      flag = false;
    }
    if(flag){
      cout << -1 << endl;
      return 0;
    }
    int index;
    for(int i = s.length() - 2; i >= 0; --i){
      if(s[i] < s[i + 1]){
        index = i; 
        break;
      }
    }
    for(int i = 0; i < index; ++i){
      cout << s[i];
    }
    int min_ch = 26;
    for(int i = index + 1; i < 26; ++i){
      if(s[i] - 'a' < min_ch && s[index] < s[i]) min_ch = s[i] - 'a';
    }
    cout << char(min_ch + 'a') << endl; 
  }
  else {
    cout << s;
    for(int i = 0; i < 26; ++i){
      if(ch_list[i] == 0){
        cout << char(i + 'a') << endl;
        break;
      }
    }

  }
}