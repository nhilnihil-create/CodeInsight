#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c = 0,a = 0,b = 0,ba = 0,i;string s;cin >> n;
  while(cin >> s){
    for(i=0;i<s.size()-1;i++){
      if(s.substr(i,2) == "AB") c++;
    }
    if(s[0]=='B' && s[s.size()-1]=='A') ba++;
    else if(s[s.size()-1]=='A') a++;
    else if(s[0]=='B') b++;
  }
  if(ba>0) c += ba-1;
  if(ba>0 && a>0){
    c++;a--;
  }
  if(ba>0 && b>0){
    c++;b--;
  }
  c += min(a,b);
  cout << c << "\n";
}