#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  
  vector<int> A(m,0);
  
  int k,a;
  rep(i,n){
    cin>>k;
    rep(j,k){
      cin>>a;
      a--;
      A[a]++;
    }
  }
  
  int ans=0;
  rep(i,m){
    if(A[i]==n) ans++;
  }
  
  cout<<ans<<endl;

  return 0;
}