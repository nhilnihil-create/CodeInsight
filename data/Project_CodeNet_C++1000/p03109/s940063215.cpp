#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  string s; 
  cin>>s;
  if(s.at(5)=='1'){
    cout<<"TBD"<<endl;
  }
  else if(s.at(5)=='0'&&s.at(6)-'0'>4){
    cout<<"TBD"<<endl;
  }
  else{
    cout<<"Heisei"<<endl;
  }
}