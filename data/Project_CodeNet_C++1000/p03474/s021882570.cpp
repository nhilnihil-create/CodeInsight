#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  string ans="Yes";
  for(int i=0;i<s.size();i++){
    if(((i==a)+(s.at(i)=='-'))%2){
      ans="No";
    }
  }
  cout << ans << endl;
}