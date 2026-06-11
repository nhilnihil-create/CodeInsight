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
  rep(i,0,N) cin>>A[i];
  int memo=0;
  int ans=0;
  int sum=0;
  int Xor=0;
  for(memo;memo<N;memo++){
      sum+=A[memo];
      Xor^=A[memo];
      if(sum!=Xor){
        sum-=A[memo];
        Xor^=A[memo];
        break;
      }
    }
  ans=memo;
  rep(i,1,N){
    sum-=A[i-1];
    Xor^=A[i-1];
    for(memo;memo<N;memo++){
      sum+=A[memo];
      Xor^=A[memo];
      if(sum!=Xor){
        sum-=A[memo];
        Xor^=A[memo];
        break;
      }
    }
    ans+=memo-i;
  }
  cout<<ans<<endl;
  }
