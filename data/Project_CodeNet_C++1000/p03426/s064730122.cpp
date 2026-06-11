#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int h,w,d;
  cin>>h>>w>>d;
  P memo[h*w+1];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int a;
      cin>>a;
      memo[a]=make_pair(i,j);
    }
  }
  int sum[h*w+1];
  for(int i=1;i<=d;i++){
    for(int j=i;j<=h*w;j+=d){
      if(j==i) sum[j]==0;
      else{
        sum[j]=sum[j-d]+abs(memo[j].first-memo[j-d].first)+abs(memo[j].second-memo[j-d].second);
      }
    }
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<sum[r]-sum[l]<<endl;
  }
  return 0;
}
