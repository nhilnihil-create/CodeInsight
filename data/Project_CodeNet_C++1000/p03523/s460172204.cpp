#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=0;
  
  for(int i=0;i<16;i++){
    string t;
    if(i%2) t+='A';
    t+="KIH";
    if(i/2%2) t+='A';
    t+='B';
    if(i/4%2) t+='A';
    t+='R';
    if(i/8%2) t+='A';
    
    if(s==t) ans++;
  }
  
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}