#include <bits/stdc++.h>
#define rep(i,n) for (int = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b;
  cin >> a >> b;
  if (a>=13){
    cout << b;
  }
  else if (6<=a && a<=12){
    cout << b/2;
  }
  else{
    cout << 0;
  }
  return 0;
}