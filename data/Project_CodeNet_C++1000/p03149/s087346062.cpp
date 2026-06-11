#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a;
  string s = "9999";
  for(int i = 0;i < 4;i++){
    cin >> a;
    s.at(i) = '0' + a;
  }
  sort(s.begin(),s.end());
  if(s == "1479"){
    cout << "YES";
  }else{
    cout << "NO";
  }
}