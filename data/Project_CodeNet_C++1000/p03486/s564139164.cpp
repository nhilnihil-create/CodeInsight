#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  
  int i, Min = min(s.size(), t.size());
  for(i=0; i<Min; i++){

    if(s[i]==t[i]) continue;
    if(s[i]>t[i]){
      cout << "No" << endl;
      return 0;
    }
    if(s[i]<t[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(s.size() < t.size()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

