#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  bool f1 = false,f4 = false,f7 = false,f9 = false;
  rep(i,4){
    int a;
    cin >> a;
    if(a == 1) f1 = true;
    if(a == 4) f4 = true;
    if(a == 7) f7 = true;
    if(a == 9) f9 = true;
  }
  if(f1 && f4 && f7 && f9) cout << "YES" << endl;
  else cout << "NO" << endl;
}