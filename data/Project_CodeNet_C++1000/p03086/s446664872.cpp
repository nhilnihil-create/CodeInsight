#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int> count(10);
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    int pre = 0;
    if(s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C'){
      pre++;
      for(int j = 1; j < s.size(); j++){
        if(s[i+j] == 'A' || s[i+j] == 'T' || s[i+j] == 'G' || s[i+j] == 'C'){
          pre++;
        }else{
          break;
        }
      }
    }
    ans = max(ans, pre);
  }
  cout << ans << endl;
}