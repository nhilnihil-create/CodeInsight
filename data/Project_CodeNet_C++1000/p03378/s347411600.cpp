#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,M,X; cin >>N >>M >>X;
  int count_a=0,count_b=0;
  rep(i,0,M) {
    int A; cin >>A;
    if (A<X) count_a++;
    else count_b++;
  }
  cout <<min(count_a,count_b) <<endl;
  return 0;
}
