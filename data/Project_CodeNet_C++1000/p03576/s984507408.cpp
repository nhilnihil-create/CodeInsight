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
  int N,K; cin>>N>>K;
  vi X(N),Y(N);
  rep(i,0,N) cin>>X[i]>>Y[i];
  int ans=-1;
  rep(i,0,N){
    rep(j,i+1,N){
      int P=min(X[i],X[j]),Q=max(X[i],X[j]);
      vi A;
      rep(k,0,N){
        if(P<=X[k]&&X[k]<=Q) A.pb(Y[k]);
      }
      sort(ALL(A));
      int M=A.size();
      if(M>=K){
      int sum=A[K-1]-A[0];
      REP(i,1,M-K){
        sum=min(sum,A[K+i-1]-A[i]);
      }
        if(ans==-1) ans=sum*(Q-P);
        else ans=min(ans,sum*(Q-P));
      }
    }
  }
  cout<<ans<<endl;
  }



