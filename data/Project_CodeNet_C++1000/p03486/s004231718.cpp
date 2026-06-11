#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  string s,t;
  char tmp;

  cin >> s  >> t;

  for(int i=0; s[i]!=0; i++){
    for(int j=i+1; s[j]!=0; j++){
      if(s[i]>s[j]){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      }
    }
  }

  for(int i=0; t[i]!=0; i++){
    for(int j=i+1; t[j]!=0; j++){
      if(t[i]<t[j]){
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
      }
    }
  }

  int l;

  if(s.length() > t.length()){
    l = s.length();
  }else{
    l = t.length();
  }

  for(int i=0;i<l;i++){
    if(s[i] == t[i]){
    }else if(s[i] > t[i]){
      cout << "No" << endl;
      break;
    }else if(s[i] < t[i]){
      cout << "Yes" << endl;
      break;
    }
    if(i == l-1){
      if(s.length() >= t.length()){
        cout << "No" << endl;
      }else{
        cout << "Yes" << endl;
      }
    }
  } 

    

//  cout << s << "\n"<< t<< endl;






}