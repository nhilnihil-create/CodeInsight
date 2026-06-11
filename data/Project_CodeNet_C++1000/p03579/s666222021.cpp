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
  int N,M; cin>>N>>M;
  vii A(N);
  rep(i,0,M){
    int X,Y; cin>>X>>Y;
    A[X-1].pb(Y-1);
    A[Y-1].pb(X-1);
  }
  vi F(N);
  F[0]=1;
  queue<pii> Q;
  Q.push(mp(0,0));
  while(Q.size()>0){
    int X=Q.front().first,Y=Q.front().second; Q.pop();
    int P=1-Y;
    rep(i,0,A[X].size()){
      int Z=A[X][i];
      bitset<2> B(F[Z]);
      if(!B.test(P)){
        F[Z]+=(1ll<<P);
        Q.push(mp(Z,P));
      }
    }
  }
  vi B(3);
  rep(i,0,N) B[F[i]-1]++;
  int ans=0;
  rep(i,0,N){
    if(F[i]==3){
      ans+=N-1-A[i].size();
    }
    else if(F[i]==2){
      ans+=B[0]+B[2]-A[i].size();
    }
    else{
      ans+=B[1]+B[2]-A[i].size();
    }
  }
  ans/=2;
  cout<<ans<<endl;
  }

