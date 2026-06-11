#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int cnt = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'o'){
      cnt++;
    }
  }
  if(8-cnt <= 15 - s.size()){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}