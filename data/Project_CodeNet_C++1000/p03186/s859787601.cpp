#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int A,B,C; cin >>A >>B >>C;
  int ans=0;
  if (A+B>=C) {
    ans=B+C;
  } else {
    ans=B+B+A+1;
  }
  cout <<ans <<endl;
  return 0;
}
