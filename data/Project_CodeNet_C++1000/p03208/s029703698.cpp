#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() { 
  int n,k;
  cin>>n>>k;
  
  vector<int> A(n);
  rep(i,n) cin>>A[i];
  
  sort(ALL(A));
  int mi=1e9;
  for(int i=0;i+k-1<n;i++){
    mi=min(mi,A[i+k-1]-A[i]);
  }
  
  cout<<mi<<endl;
  
  return 0;
}