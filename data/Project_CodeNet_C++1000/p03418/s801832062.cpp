#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)


int main() {
  int N,K;
  cin >> N >> K;
  ll cnt=0;
  rep2(b,K+1,N+1) {
    // cout << N/b*(b-K) + max(N%b-K+1,0) << endl;
    cnt += N/b*(b-K) + max(N%b-K+1,0);
  }
  if (K==0) cnt-=N;
  cout << cnt << endl;
}