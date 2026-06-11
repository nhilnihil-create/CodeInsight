#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  string s;
  cin >> s;
  int n=s.size();
  if(s[0]!='A'){
    cout << "WA" << endl;
    return 0;
  }
  int cnt=0;
  int num;
  for(int i = 2; i < n-1; ++i){
    if(s[i]=='C'){
      cnt++;
      num=i;
    }
    
  }
  if(cnt!=1){
    cout << "WA" << endl;
    return 0;
  }
  s.erase(num,1);
  for(int i = 1; i < n-1; ++i){
    if(s[i]<97) {
      cout << "WA" << endl;
      return 0;
    }
  }
  cout << "AC" << endl;
  return 0;
}