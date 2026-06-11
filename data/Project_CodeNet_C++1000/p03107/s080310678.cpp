#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int z=0,o=0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='0')z++;
    else if(s[i]=='1')o++;
  }
  cout << min(z,o)*2 << endl;
}