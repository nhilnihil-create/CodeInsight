#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<P> p(n);
  rep(i,n){
    int m;
    cin>>m;
    p[i]=make_pair(m,i);
  }
  sort(p.begin(),p.end());
  int ans=n;
  int tmp=1;
  rep(i,n-1){
    if(p[i].second<p[i+1].second){
      tmp++;
    }else{
      ans=min(ans,n-tmp);
      tmp=1;
    }
  }
  ans=min(ans,n-tmp);
  cout<<ans<<endl;
}