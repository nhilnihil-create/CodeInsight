#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); ++i)
typedef long long ll;

int main(){
  int a,b,x; cin >> a >> b >> x;
  if(x<a||a+b<x) cout << "NO";
  else cout << "YES";
  return 0;
}