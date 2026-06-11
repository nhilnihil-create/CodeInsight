#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans=0;
  for(auto str:s){
    if(str=='+')ans++;
    else ans--;
  }
  cout << ans << endl;
}