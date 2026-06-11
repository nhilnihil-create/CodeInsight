#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s;
  for(int i=0;i<(1<<4);i++){
    int bit=i;
    t="";
    t+=((bit%2)?"A":"");
    bit/=2;
    t+="KIH";
    t+=((bit%2)?"A":"");
    bit/=2;
    t+="B";
    t+=((bit%2)?"A":"");
    bit/=2;
    t+="R";
    t+=((bit%2)?"A":"");
    if(s==t){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
