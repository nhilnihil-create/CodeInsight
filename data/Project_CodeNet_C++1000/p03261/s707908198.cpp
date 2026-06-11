#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  int n;
  vector<string> w(200);
  cin >> n;
  bool flag = 1;
  for(int i = 0; i < n; i++) {
    cin >> w[i];
    for(int j = 0; j < i; j++) {
      if(w[j] == w[i]) flag = 0;
      if(j == i-1 & w[j].back() != w[i].front())
        flag = 0;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl; 
}