#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N; cin >>N;
  string A,B,C; cin >>A >>B >>C;
  int ans=0;
  rep(i,0,N) {
    set<char> a;
    a.insert(A[i]);
    a.insert(B[i]);
    a.insert(C[i]);
    ans+=a.size()-1;
  }
  cout <<ans <<endl;
  return 0;
}
