#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  char x,y;
  cin >> x >> y;
  if(x > y) cout << ">" << endl;
  else if(x < y) cout << "<" << endl;
  else cout << "=" << endl;
}