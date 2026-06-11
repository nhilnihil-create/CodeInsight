#include<iostream>
using namespace std;
int main(){
  string s;
  int n,k;
  cin >> n >> k >> s;
  k=k-1;
  if(s.at(k)=='A'){
    s.at(k)='a';
  }
  else if(s.at(k)=='B'){
    s.at(k)='b';
  }
  else{
    s.at(k)='c';
}
  cout << s << endl;
}