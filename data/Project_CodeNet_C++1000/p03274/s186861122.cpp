#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> x(n);
  rep(i,n){
    cin>>x[i];
  }
  ll ans=LLONG_MAX;
  rep(i,n-k+1){
    ll left=x[i], right=x[i+k-1];
    ll now_ans=0;
    if(left<0 && right>0){
      now_ans=min(abs(left)*2+right,abs(right)*2+abs(left));
    }else{
      now_ans=max(abs(left),abs(right));
    }
    ans=min(ans,now_ans);
  }
  cout<<ans<<endl;
}

