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
  vi A(N+1,-1);
  REP(i,1,N) cin>>A[i];
  int ans=0;
  bool flag=1;
  REP(i,1,N){
    if(A[i-1]+1<A[i]){
      ans=-1;
      flag=0;
    }
  }
  if(flag){
  map<int,int> M;
  REP(i,1,N){
    int X=i-A[i];
    M[X]=max(M[X],A[i]);
  }
  for(auto p:M) ans+=p.second;
  }
  cout<<ans<<endl;
  }
