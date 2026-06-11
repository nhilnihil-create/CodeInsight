#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<int> L(n);
  rep(i,n) cin>>L[i];
  
  sort(ALL(L));
  
  int sum=0;
  rep(i,n-1) sum+=L[i];
  
  if(L[n-1]<sum) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}