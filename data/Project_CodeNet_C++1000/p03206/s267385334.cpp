#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int D;cin>>D;
  string x = "Christmas",y="Eve";
  if(D==25) cout << x << endl;
  if(D==24) cout << x << " " << y << endl;
  if(D==23) cout << x << " " << y << " " << y << endl;
  if(D==22) cout << x << " " << y << " " << y << " " << y << endl;
}