#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int k; cin >> k;
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == '1'){
      if(i == k-1){
        cout << 1 << endl;
        return 0;
      }
      continue;
    }
    else{
      cout << s.at(i) << endl;
      break;
    }
  }
}
