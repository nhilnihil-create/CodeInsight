#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  string s; cin>>s;
  if(s.at(0)=='0'&&s.at(1)!='0'
    ||s.at(0)=='1'&&s.at(1)=='0'
    ||s.at(0)=='1'&&s.at(1)=='1'
    ||s.at(0)=='1'&&s.at(1)=='2'){
    
    if(s.at(2)=='0'&&s.at(3)!='0'
    ||s.at(2)=='1'&&s.at(3)=='0'
    ||s.at(2)=='1'&&s.at(3)=='1'
    ||s.at(2)=='1'&&s.at(3)=='2'){
      cout<<"AMBIGUOUS";}
    else{cout<<"MMYY";}
  }
  else if(s.at(2)=='0'&&s.at(3)!='0'
    ||s.at(2)=='1'&&s.at(3)=='0'
    ||s.at(2)=='1'&&s.at(3)=='1'
    ||s.at(2)=='1'&&s.at(3)=='2'){
    cout<<"YYMM";}
  else{cout<<"NA";}
}