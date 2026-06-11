#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int a,b; cin >>a >>b;
  char ans='x';
  if (a+b==15) {
    ans='+';
  } else if (a*b==15) {
    ans='*';
  }
  cout <<ans <<endl;
  return 0;
}
