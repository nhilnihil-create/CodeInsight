#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
#define ll long long
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> A(n);
  rep(i, n) cin>>A[i];

  ll ans=0;
  int right=0;
  int X=0;
  for (int left=0; left<n; left++) {
    while ((right<n)&&((X+A[right])==(X^A[right]))) {
      X+=A[right];
      right++;
    }
    ans+=right-left;
    if (right==left) right++;
    else X-=A[left];
  }
  cout<<ans<<endl;
}