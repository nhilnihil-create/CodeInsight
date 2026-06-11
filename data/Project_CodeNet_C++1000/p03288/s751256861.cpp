#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int r;
  cin >>r;
  if(r<1200) cout << "ABC" << endl;
  if(r>=1200 && r<2800) cout << "ARC" << endl;
  if(r>=2800) cout << "AGC" << endl;
  return 0;
}
