#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int Sum=0, A=S.at(0)-'0';
  bool N=1;
  for(int i=1; i<S.size(); i++){
    if(S.at(i)!='9') N=0;
  }
  Sum+=(S.size()-1)*9;
  if(S.size()!=1 && N==0) Sum=Sum+A-1;
  else Sum+=A;
  cout << Sum << endl;
}