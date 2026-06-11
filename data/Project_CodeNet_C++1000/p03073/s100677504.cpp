#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  int S = s.size();
  for(int i=0; i<S; i++){
    if(i>=1){
      if(s[i] == '0' && s[i] == s[i-1]){
        count++;
        s[i] = '1';
      }
      if(s[i] == '1' && s[i] == s[i-1]){
        count++;
        s[i] = '0';
      }
    }
  }
  
  cout << min(count,S-count) << endl;
  
	return 0;
}
