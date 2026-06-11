#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  cin >> str;
  string t = "keyence";
  if(str == t){
    cout << "YES" << endl;
    return 0;
  }
  int n = str.size();
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      string S = "";
      for(int k = 0; k < n; k++){
        if(i <= k && k <= j) continue;
        else S.push_back(str[k]);
      }
      if(S == t){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
