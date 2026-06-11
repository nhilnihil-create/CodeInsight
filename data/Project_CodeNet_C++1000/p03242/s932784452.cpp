#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
string s;
cin >> s;
rep(i,3){
  if(s.at(i) =='1') s.at(i) = '9';
  else s.at(i) = '1';
}
cout << s << endl;
}
  
