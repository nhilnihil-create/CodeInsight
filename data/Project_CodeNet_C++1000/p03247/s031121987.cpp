#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll X[1010], Y[1010];
int dx[4]={1,-1,1,-1};
int dy[4]={1,-1,-1,1};
char m[4]={'R','L','U','D'};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N; cin>>N;
  cin>>X[0]>>Y[0];
  int f=(abs(X[0])+abs(Y[0]))%2;
  for(int i=1;i<N;i++){
    cin>>X[i]>>Y[i];
    if(f!=(abs(X[i])+abs(Y[i]))%2){
      cout<<-1<<endl;
      return 0;
    }
  }
  
  
  vector<ll> D;
  if(f==0) D.push_back(1);
  rep(i,33) D.push_back(1LL<<i);
  sort(D.rbegin(),D.rend());
  cout<<D.size()<<endl;
  for(ll d:D) cout<<d<<" ";
  cout<<endl;

  rep(i,N){
    ll x=X[i]+Y[i], y=X[i]-Y[i];
    ll xx=0,yy=0;
    for(ll d:D){
      ll best=LLONG_MAX;
      int b=-1;
      rep(k,4){
        ll tx=xx+d*dx[k], ty=yy+d*dy[k];
        if(abs(tx-x)+abs(ty-y)<best){
          b=k;
          best=abs(tx-x)+abs(ty-y);
        }
      }
      xx+=d*dx[b], yy+=d*dy[b];
      cout<<m[b];
    }
    cout<<'\n';
  }
  return 0;
}
