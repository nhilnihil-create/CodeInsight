#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  ll ans=0;
  vector<int> sum(n);
  rep(i,n){
    int a,b;
    cin>>a>>b;
    sum[i]=a+b;
    ans-=b;
  }
  sort(sum.begin(),sum.end(),greater<int>());
  rep(i,n){
    ans+=sum[i];
    i++;
  }
  cout<<ans<<endl;
}