#include <bits/stdc++.h>
using namespace std;
using vs = vector<char>;
bool ok(vs a){
  int n = a.size();
  bool flag = true;
  for(int i=0;i<n;i++){
    if(!(a.at(i)=='A' || a.at(i)=='T' || a.at(i)=='C' || a.at(i)=='G') ){
      flag = false;
    }
  }
  return flag;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vs ss(n);
  for(int i=0;i<n;i++){
    ss.at(i) = s.at(i);
  }
  int max = 0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      vs sss = vector(ss.begin() + i, ss.begin() + j + 1);
      if(ok(sss)){
        if(j-i+1 > max){
          max = j-i+1;
        }
      }
    }
  }
  cout << max << endl;
}