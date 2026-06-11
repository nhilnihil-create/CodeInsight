#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  bool f = false;
  rep(i,0,n){
    char s;
    cin >> s;
    if(s == 'Y') f = true;
  }
  if(f) cout << "Four" << endl;
  else cout << "Three" << endl;
}