#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string s = "";
  while(N != 0) {
    if(N % -2 != 0){
      --N;
      s = "1"+s;
    } 
    else s = "0"+s;
    N /= -2;
  }
  if(s == "")	s = "0";
  cout << s << endl;
}