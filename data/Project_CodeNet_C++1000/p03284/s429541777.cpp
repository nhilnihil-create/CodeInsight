#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  
  if(n%k==0) cout<<0<<endl;
  else cout<<1<<endl;
  
  return 0;
}