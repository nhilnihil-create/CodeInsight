#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
  	string YES = "Yes";
    string NO = "No";
    int ans = 0;
  
    cin >> s;
    
  for(int i = 0; i < 3;i++){
    if(s[i] == s[i+1]){
      ans++;
    }
    else{
      ans = 0;
    }
    if(ans == 2) break;
  }
  
  if(ans==2){
    cout << YES << endl;
  }
  else{
    cout << NO << endl;
  }
  
}