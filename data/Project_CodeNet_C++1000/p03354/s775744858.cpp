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
  rep(i,0,N) cin>>B[i];
  rep(i,0,M){
    int X,Y; cin>>X>>Y;
    A[X-1].pb(Y-1);
    A[Y-1].pb(X-1);
  }
  int ans=0;
  vector<bool> F(N,1);
  rep(i,0,N){
    if(F[i]){
      F[i]=0;
      queue<int> Q;
      Q.push(i);
      set<int> S,T;
      S.insert(i);
      T.insert(B[i]-1);
      while(Q.size()>0){
        int K=Q.front();
        Q.pop();
        rep(j,0,A[K].size()){
          int P=A[K][j];
          if(F[P]){
            Q.push(P);
            F[P]=0;
            S.insert(P);
            T.insert(B[P]-1);
          }
        }
      }
      for(auto p:S){
        if(T.count(p))
          ans++;
      }
    }
  }
  cout<<ans<<endl;
  }
