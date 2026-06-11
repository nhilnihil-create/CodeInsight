#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int N; cin >>N;
  int ans=0;
  for (int i=1;;i++) {
    if (N<i*i) {
      ans=(i-1)*(i-1);
      break;
    }
  }
  cout <<ans <<endl;
}
