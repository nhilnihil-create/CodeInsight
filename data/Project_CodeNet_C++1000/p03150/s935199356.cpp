#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s == "keyence"){
    cout << "YES" << endl;
    return 0;
  }
  for(int i = 0; i < s.size(); i++){
    for(int j = i; j < s.size(); j++){
      string t = s;
      t.erase(i, j - i + 1);
      if(t == "keyence"){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
