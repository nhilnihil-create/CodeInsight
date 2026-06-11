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
  int N,A,B; cin>>N>>A>>B;
  int P=0,Q=0,R=0;
  rep(i,0,N){
    int X; cin>>X;
    if(X<=A)
      P++;
    else if(B<X)
      R++;
    else
      Q++;
  }
  cout<<min(P,min(Q,R))<<endl;
  
  }
