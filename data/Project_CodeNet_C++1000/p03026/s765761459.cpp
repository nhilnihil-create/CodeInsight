#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pb push_back
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
signed main(){
  int N; cin>>N;
  vii A(N);
  rep(i,1,N){
    int X,Y; cin>>X>>Y;
    A[X-1].pb(Y-1);
    A[Y-1].pb(X-1);
    }
  vi C(N);
  rep(i,0,N) cin>>C[i];
  sort(ALL(C),greater<int>());
  int sum=0;
  rep(i,1,N) sum+=C[i];
  cout<<sum<<endl;
  vi F(N,-1);
  F[0]=0;
  int count=1;
  queue<int> Q;
  Q.push(0);
  while(Q.size()>0){
    int X=Q.front(); Q.pop();
    rep(i,0,A[X].size()){
      int Y=A[X][i];
      if(F[Y]==-1){
        F[Y]=count++;
        Q.push(Y);
        }
      }
    }
  rep(i,0,N) cout<<C[F[i]]<<" ";
  cout<<endl;
  }
