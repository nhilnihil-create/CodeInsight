#include<bits/stdc++.h>
using namespace std;

int main(){
  map<string, int> mp;
  string word_before = "";
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    mp[s]++;
    if(i == 0){
      word_before = s;
      reverse(word_before.begin(), word_before.end());
      continue;
    }
    if(word_before[0] != s[0] || mp[s] > 1){
      cout << "No" << endl;
      return 0;
    }
    word_before = s;
    reverse(word_before.begin(), word_before.end());
  }
    cout << "Yes" << endl;
}