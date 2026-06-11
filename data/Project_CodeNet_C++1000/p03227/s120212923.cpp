#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
 cin >> s;
  if(s.size() == 3){
    cout << s.at(2) << s.at(1) << s.at(0);
  }
  else
  {
    cout << s;
  }
}