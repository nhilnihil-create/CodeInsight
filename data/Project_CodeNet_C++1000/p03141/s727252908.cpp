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
  priority_queue<pair<pii,int>> P,Q;
  rep(i,0,N){
    cin>>A[i]>>B[i];
    P.push(mp(mp(A[i]+B[i],A[i]),i));
    Q.push(mp(mp(A[i]+B[i],B[i]),i));
  }
  int ans=0;
  vector<bool> F(N,1);
  rep(i,0,N){
    if(i%2==0){
      while(1){
        int X=P.top().first.first,Y=P.top().first.second,Z=P.top().second;
        P.pop();
        if(F[Z]){
          F[Z]=0;
          ans+=Y;
          break;
        }
      }
    }
    else{
      while(1){
        int X=Q.top().first.first,Y=Q.top().first.second,Z=Q.top().second;
        Q.pop();
        if(F[Z]){
          F[Z]=0;
          ans-=Y;
          break;
        }
      }
    }
  }
  cout<<ans<<endl;
  }
