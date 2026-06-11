#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;
bool f(int a, int b , int c) {
  if(a+b>=c) return true;
  else return false;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  yorn(f(a, b, c));
  return 0;
}