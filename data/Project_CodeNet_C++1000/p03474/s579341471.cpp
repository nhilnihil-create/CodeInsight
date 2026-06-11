#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string s;
  cin >> a >> b >> s;
  if(s[a] == '-'){
    for(int i = 0; i < s.size(); i++){
      if(i != a){
      if(!(s[i] >= 48 && s[i] <= 57)){
        cout << "No" << endl;
        return 0;
      }
    }
    }
    cout << "Yes" << endl;
    return 0;
  }else{
    cout << "No" << endl;
    return 0;
  }
}