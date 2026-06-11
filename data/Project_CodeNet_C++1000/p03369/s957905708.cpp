#include <bits/stdc++.h>
using namespace std;


int main() {

  string s;
  cin>>s;

  int money=700;

  for(int i=0;i<s.size();i++){
    if(s.at(i)=='o')
      money+=100;
  }

  cout<<money<<endl;

  return 0;
}

