#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)n;i++)
using namespace std;
int main(){
  //一致させることができるか
  int b=0;
  string s, s1, t, min_s;
  cin >> s >> t;
  s1=s;
  rep(i, s.size()-t.size()+1){
    int k=0;
    for(int j=i;j<i+t.size(); j++){
      if(s.at(j)==t.at(j-i)) continue;
      else if(s.at(j)=='?') s.at(j)=t.at(j-i);
      else {
        k=1;
        break;
      }
    }
    if(k!=1){
      for(int j=0;j<s.size();j++){
      if(s.at(j)=='?') s.at(j)='a';
      }
    }
    else if(k==1) {
      s=s1;
      continue;
    }
    if(b==0) b=1;
    else b=2;
      
    if(b==1) {
      min_s=s;
      //cout << min_s << endl;
    }
    else {
      if(s<min_s) min_s=s;
    }
    //if(i==2) cout << min_s << endl;
    s=s1;
    //cout << min_s << endl;
  }
  if(b==0) cout << "UNRESTORABLE" << endl;
  else cout << min_s << endl;
  //cout <<  << endl;
}


    
    