#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<int> A(n);
  int x;
  rep(i,n){
    cin>>x;
    A[i]=x-i-1;
  }
  sort(ALL(A));
  int m=A[n/2];
  
  ll ans=0;
  rep(i,n){
    ans+=abs(A[i]-m);
  }
  cout<<ans<<endl;

  return 0;
}