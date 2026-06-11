#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  bool ans=true;
  for(int i=0;i<s.size();i++){
    if((s.at(i)=='-'&&i!=a)||(s.at(i)!='-'&&i==a))
      ans=false;
  }
  cout << (ans?"Yes":"No");
}