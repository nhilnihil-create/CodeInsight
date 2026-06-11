#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  //cout << s << " " << t << endl;
  for(int i=0;i<min(s.length(),t.length());i++){
    if(s.at(i) > t.at(i)){
      cout << "No" << endl;
      return(0);
    }else if(s.at(i) < t.at(i)){
      cout << "Yes" << endl;
      return(0);
    }
  }
  
  if(s.length() < t.length()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return(0);
}