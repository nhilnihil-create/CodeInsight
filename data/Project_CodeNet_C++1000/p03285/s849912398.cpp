#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  int a = n;
  bool ok = false;
  while(n>0){
    if(n%7 == 0) ok = true;
    n -= 4;
  }
  while(a>0){
    if(a%4 == 0) ok = true;
    a -= 7;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
