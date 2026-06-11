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
  int N,A,B; cin >>N >>A >>B;
  cout <<((B-A)%2==0 ? "Alice":"Borys") <<endl;
  return 0;
}
