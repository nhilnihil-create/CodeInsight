#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string answer="Heisei";
  
  int a=s.at(5)-48,b=s.at(6)-48;
  
  if(a==1||b>4){
    answer="TBD";
  }
  cout << answer << endl;
}