#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N; cin>>N;
  vi A(N),B(N);
  rep(i,0,N) cin>>A[i]>>B[i];
  int ans=0;
  vi C,D;
  rep(i,0,N){
    if(A[i]<B[i]) ans+=A[i];
    else if(A[i]>B[i]){
      ans+=A[i]-B[i];
      C.pb(B[i]);
    }
    else D.pb(A[i]);
  }
  sort(ALL(C),greater<int>());
  rep(i,0,C.size()-1) ans+=C[i];
  if(D.size()!=N){
    rep(i,0,D.size()) ans+=D[i];
  }
  cout<<ans<<endl;
  }

