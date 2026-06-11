#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
 
int main(){
  ll N,K;
  cin>>N>>K;
  VL A(N);
  rep(i,N) cin>>A[i];
  if(K==0){
    ll sum=0;
    rep(i,N) sum+=A[i];
    cout<<sum<<endl;
    return 0;
  }
  VL X(40);
  rep(i,40) X[i]=(K>>i)&1;
  ll keta;
  rep(i,40){
    if(X[39-i]){
      keta=40-i;
      break;
    }
  }
  VVL Y(N,VL(40));
  rep(i,N) rep(j,40) Y[i][j]=(A[i]>>j)&1;
  int F=1;
  VL ans(40);
  rep(i,40){
    int cnt=0;
    rep(j,N) cnt+=Y[j][39-i];
    if(cnt*2>N){
      ans[39-i]=0;
      if(X[39-i]) F=0;
    }else if(cnt*2<N){
      if(F) ans[39-i]=X[39-i];
      else ans[39-i]=1;
    }else{
      if(F){
        if(X[39-i]){
          ans[39-i]=0;
          F=0;
        }else ans[39-i]=0;
      }else ans[39-i]=0;
    }
  }
  ll Z=0;
  VL Q(40);
  Q[0]=1;
  rep(i,39) Q[i+1]=Q[i]*2;
  rep(i,40) Z+=Q[i]*ans[i];
  ll B=0;
  rep(i,N) B+=Z^A[i];
  cout<<B<<endl;
}