#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int A,B,C,X; cin >>A >>B >>C >>X;
  int ans=0;
  rep_eq(i,0,A) {
    rep_eq(j,0,B) {
      rep_eq(k,0,C) {
        int temp=500*i+100*j+50*k;
        if (temp==X) ans++;
      }
    }
  }
  cout <<ans <<endl;
  return 0;
}
