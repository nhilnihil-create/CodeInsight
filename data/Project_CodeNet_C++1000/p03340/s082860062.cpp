#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vl=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N; cin >>N;
  vi A(N);
  rep(i,0,N) {cin >>A[i];}
  ll ans=0;
  int right=0;
  int sum=0;
  rep(left,0,N) {
    while (right<N && (sum^A[right])==(sum+A[right])) {
      sum+=A[right];
      right++;
    }
    ans+=right-left;
    if (left==right) {
      right++;
    } else {
      sum-=A[left];
    }
  }
  cout <<ans << endl;
  return 0;
}
