#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main(){
  int count=0;
  string s;
  cin >> s;
  r(i,s.length()){
    if(s.at(i)=='x')count++;
  }
  if(count>=8)cout << "NO"<<endl;
  else cout << "YES"<<endl;
}