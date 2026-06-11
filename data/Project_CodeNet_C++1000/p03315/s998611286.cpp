#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, 4) {
    if(s[i] == '+') cnt++;
    else if(s[i] == '-') cnt--;
  }
  
  cout << cnt << endl;
}