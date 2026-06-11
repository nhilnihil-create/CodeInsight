#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(max(a,c) - min(a,c) <= d){
    cout << "Yes";
    return 0;
  }
  else if(max(a,b) - min(a,b) <= d && max(c,b) - min(c,b) <= d ){
   cout << "Yes";
    return 0;
  }
  else{
    cout << "No";
  }
  return 0;
}