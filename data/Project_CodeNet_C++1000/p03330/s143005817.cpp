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
  int N,C; cin>>N>>C;
  vii D(C,vi(C));
  vii A(3,vi(C));
  rep(i,0,C){
    rep(j,0,C){
      cin>>D[i][j];
    }
  }
  REP(i,1,N){
    REP(j,1,N){
      int X; cin>>X;
      A[(i+j)%3][X-1]++;
    }
  }
  vii B(3,vi(C));
  rep(i,0,3){
    rep(j,0,C){
      rep(k,0,C)
        B[i][j]+=A[i][k]*D[k][j];
    }
  }
  int ans=MOD;
  rep(i,0,C){
    rep(j,0,C){
      rep(k,0,C){
        if(i==j||j==k||k==i)
          continue;
        ans=min(ans,B[0][i]+B[1][j]+B[2][k]);
      }
    }
  }
  cout<<ans<<endl;
  }
