#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main() {
  
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  if(abs(a-b) <= d && abs(b-c) <= d || abs(a-c) <= d) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}