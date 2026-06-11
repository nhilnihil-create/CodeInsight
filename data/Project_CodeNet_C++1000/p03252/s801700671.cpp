#include<bits/stdc++.h>
using namespace std;


int main(){
  string s,t;
  cin >> s;
  cin >> t;
  int n=s.size();
  map<char,char> ma,ima;
  bool ok=true;
  for(int i=0;i<n;++i){
    if(ma.count(s[i])) if(ma[s[i]]!=t[i]) ok=false;
    if(ima.count(t[i])) if(ima[t[i]]!=s[i]) ok=false;
    ma[s[i]]=t[i];
    ima[t[i]]=s[i];
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
