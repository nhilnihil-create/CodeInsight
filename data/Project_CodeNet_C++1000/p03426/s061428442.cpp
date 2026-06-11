#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int dis(P x,P y){
  return abs(x.first-y.first)+abs(x.second-y.second);
}

int main(){
  int h,w,d;
  cin>>h>>w>>d;
  P b[h*w+1];
  rep(i,0,h){
    rep(j,0,w){
      int a;
      cin>>a;
      b[a]=P(i,j);
    }
  }
  int sum[h*w+1];
  sum[0]=0;
  rep(i,1,h*w+1){
    if(i<=d) sum[i]=0;
    else sum[i]=sum[i-d]+dis(b[i],b[i-d]);
  }
  int q;
  cin>>q;
  rep(i,0,q){
    int l,r;
    cin>>l>>r;
    cout<<sum[r]-sum[l]<<endl;
  }
}