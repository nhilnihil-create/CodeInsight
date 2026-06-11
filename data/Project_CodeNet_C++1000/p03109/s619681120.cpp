#include <bits/stdc++.h>
using namespace std;


int main() {

  string s;
  cin>>s;

  string year=s.substr(0,4);
  string month=s.substr(5,2);
  string day=s.substr(8,2);

  if(year<="2019"&&month<="04"&&day<="30")
    cout<<"Heisei"<<endl;
  else
    cout<<"TBD"<<endl;

  return 0;
}

