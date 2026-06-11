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
signed main(){
  int N,K; cin>>N>>K;
  vector<pii> A(N);
  rep(i,0,N) cin>>A[i].second>>A[i].first;
  sort(ALL(A),greater<pii>());
  int sum=0;
  map<int,int> M;
  priority_queue<int,vi,greater<int>> S;
  rep(i,0,K){
    sum+=A[i].first;
    if(M.count(A[i].second))
      S.push(A[i].first);
    else
      M[A[i].second]=A[i].first;
  }
  int Q=M.size();
  int ans=sum+Q*Q;
  rep(i,K,N){
    if(S.size()==0)
      break;
    if(!M.count(A[i].second)){
      sum-=S.top();
      S.pop();
      sum+=A[i].first;
      M[A[i].second]=A[i].first;
      int P=M.size();
      ans=max(ans,sum+P*P);
    }
  }
  cout<<ans<<endl;
  }

