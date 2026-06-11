#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main(){
  string s;cin>>s;
  string t=s.substr(5,2);
  if(t.at(0)=='0'){
    if(t.at(1)=='1'||t.at(1)=='2'
       ||t.at(1)=='3'||t.at(1)=='4'){
      cout<<"Heisei";     
    }
    else{cout<<"TBD";}
  }
  else{cout<<"TBD";}
}