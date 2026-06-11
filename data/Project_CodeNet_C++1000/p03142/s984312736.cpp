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
  vi B(N);
  rep(i,1,N+M){
    int X,Y; cin>>X>>Y;
    A[X-1].pb(Y-1);
    B[Y-1]++;
  }
  stack<int> Q;
  vi C;
  rep(i,0,N){
    if(B[i]==0) Q.push(i);
  }
  while(Q.size()>0){
    int X=Q.top();
    Q.pop();
    C.pb(X);
    rep(i,0,A[X].size()){
      int Y=A[X][i];
      B[Y]--;
      if(B[Y]==0) Q.push(Y);
    }
  }
  vi D(N);
  rep(i,0,N){
    int X=C[i];
    rep(j,0,A[X].size()){
      int Y=A[X][j];
      D[Y]=C[i]+1;
    }
  }
  rep(i,0,N) cout<<D[i]<<endl;
  }

