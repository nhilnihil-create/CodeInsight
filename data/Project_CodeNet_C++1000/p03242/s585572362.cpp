#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

int main() {
  string num;
  cin >> num;
  rep (i,3) {
    if(num.at(i) == '1') num.at(i)='9';
    else if (num.at(i) == '9') num.at(i)='1';
  }
  cout << num << endl;
  return 0;
}