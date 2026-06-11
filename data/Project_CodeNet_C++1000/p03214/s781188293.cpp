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
  int N; cin>>N;
  vi A(N);
  double av=0;
  rep(i,0,N){
    cin>>A[i];
    av+=A[i];
  }
  av=av*1.0/N;
  double memo=MOD;
  int ans;
  rep(i,0,N){
    if(memo>abs(av-(double)A[i])){
      memo=abs(av-(double)A[i]);
      ans=i;
    }
  }
  cout<<ans<<endl;
  }
