#include<bits/stdc++.h>
using namespace std;

int main(){
  int m;
  string s;
  cin >> s;
  m=s.at(6)-'0'+(s.at(5)-'0')*10;
  if(m>4){
    cout << "TBD" << endl;
  }else{
    cout << "Heisei" << endl;
  }
}