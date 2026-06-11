#include<bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  int f=0;
  string s=to_string(x);
  for(int i=0;i<s.size();i++){
    f+=s.at(i)-48;
  }
  cout << ((x%f==0)?"Yes":"No") << endl;
}