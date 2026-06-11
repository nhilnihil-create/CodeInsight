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
signed main(){
  int N; cin>>N;
  vi A(N),B(N);
  int ans=0;
  rep(i,0,N) cin>>A[i]>>B[i];
  vector<pii> C(N);
  rep(i,0,N) cin>>C[i].first>>C[i].second;
  sort(ALL(C));
  vector<bool> F(N,1);
  rep(i,0,N){
    int memo=-1,Max=-1;
    rep(j,0,N){
      if(A[j]<C[i].first&&F[j]&&C[i].second>B[j]){
        if(Max<B[j]){
          memo=j;
          Max=B[j];
          }
        }
      }
    if(memo!=-1){
      ans++;
      F[memo]=0;
      }
    }
  cout<<ans<<endl;
  }
