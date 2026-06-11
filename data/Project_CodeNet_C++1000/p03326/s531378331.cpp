#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  
  vector<ll> X(n),Y(n),Z(n);
  rep(i,n) cin>>X[i]>>Y[i]>>Z[i];
  
  ll ma=0;
  rep(i,8){
    int a=1,b=1,c=1;
    if(i&1) a=-1;
    if(i&(1<<1)) b=-1;
    if(i&(1<<2)) c=-1;
    vector<ll> A(n);
    rep(j,n) A[j]=a*X[j]+b*Y[j]+c*Z[j];
    sort(ALL(A));
    reverse(ALL(A));
    ll sum=0;
    rep(j,m) sum+=A[j];
    ma=max(ma,sum);
  }
  cout<<ma<<endl;
    
  return 0; 
}