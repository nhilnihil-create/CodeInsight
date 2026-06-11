#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n,k;
  cin >>n >>k;
  string s;
  cin >>s;
  k--;
  s[k]+=32;
  cout << s << endl;
}