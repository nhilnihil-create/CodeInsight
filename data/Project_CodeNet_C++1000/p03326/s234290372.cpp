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
  vi A(N),B(N),C(N),P={1,-1};
  rep(i,0,N) cin>>A[i]>>B[i]>>C[i];
  int ans=0;
  rep(a,0,2){
    rep(b,0,2){
      rep(c,0,2){
        vi D(N);
        rep(i,0,N){
          D[i]=P[a]*A[i]+P[b]*B[i]+P[c]*C[i];
        }
        sort(ALL(D));
        reverse(ALL(D));
        int sum=0;
        rep(i,0,M){
          sum+=D[i];
        }
        ans=max(ans,sum);
      }
    }
  }
  cout<<ans<<endl;
  }

