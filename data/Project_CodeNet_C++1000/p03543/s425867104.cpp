#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  int ans=0;
  int count=0;
  char x = s[0];
  for(int i=1; i<s.size(); i++){
    if(x==s[i]){
      count++;
      ans = max(ans,count);
    }else{
      count=0;
      x=s[i];
    }
  }
  
  if(ans>=2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
  