#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  
  if (b-a+1 <= 2*k)
    rep(i,b-a+1) cout << i+a << endl;
  else {
    rep(i,k) cout << i+a << endl;
    rep(i,k) cout << i+(b-k+1) << endl;
  }
}