#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  long long n,m;
  cin>>n>>m;
  long long ans;
  if(n>m) swap(n,m);
  if(n==1){
    if(m==1) ans=1;
    else ans=m-2;
  }
  else if(n==2) ans=0;
  else ans=(n-2)*(m-2);
  cout<<ans<<endl;
}