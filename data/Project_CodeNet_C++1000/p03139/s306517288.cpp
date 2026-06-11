#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,A,B; cin >>N >>A >>B;
  int max_val=min(A,B);
  int min_val=max(0,max_val-N+max(A,B));
  cout <<max_val <<' ' <<min_val <<endl;
  return 0;
}
