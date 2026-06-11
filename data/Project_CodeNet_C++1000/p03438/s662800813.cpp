#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }
  ll a_cnt=0, b_cnt=0;
  rep(i,n){
    if(a[i]<b[i]){
      a_cnt+=((b[i]-a[i]+1)/2);
      if((b[i]-a[i])%2!=0) b_cnt++;
    }
    if(a[i]>b[i]) b_cnt+=a[i]-b[i];
  } 
  if(a_cnt>=b_cnt) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

