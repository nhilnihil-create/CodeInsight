#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  int A,B,X; cin >>A >>B >>X;
  if (A>X) {
    cout <<"NO" <<endl;
    return 0;
  } else if (A==X) {
    cout <<"YES" <<endl;
    return 0;
  } else if (B>=X-A) {
    cout <<"YES" <<endl;
    return 0;
  }
  cout <<"NO" <<endl;
  return 0;
}
