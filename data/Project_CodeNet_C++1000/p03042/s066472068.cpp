#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include<iostream>
#include<string>

bool judge(string s) {
  return "01" <= s && s <= "12"; 
}

int main() {
  string S;
  cin >> S;
  string A = S.substr(0,2);
  string B = S.substr(2,2);
  //cout << A << B << endl;
  if (judge(A) && judge(B)) {
    cout << "AMBIGUOUS" << endl;
  } else if (judge(A)) {
    cout << "MMYY" << endl;
  } else if (judge(B)) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }

  return 0;
}