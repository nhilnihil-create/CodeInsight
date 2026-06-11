#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() { 
  int n;
  cin>>n;
  
  vector<int> A(n);
  rep(i,n) cin>>A[i];
  
  sort(ALL(A));
  int sum=0;
  rep(i,n){
    if(i!=n-1) sum+=A[i];
    else sum+=A[i]/2;
  }
  
  cout<<sum<<endl;
  
  return 0;
}