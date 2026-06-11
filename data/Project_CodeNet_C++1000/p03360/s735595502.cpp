#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  rep(i,k){
    int s = max({a,b,c});
    if(s==a) a=a*2;
    else if(s==b) b=b*2;
    else c=c*2;
  } 
  cout << a+b+c << endl; 
  return 0;
}