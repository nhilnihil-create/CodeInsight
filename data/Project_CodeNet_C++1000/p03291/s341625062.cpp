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
  string S; cin>>S;
  int N=S.size();
  vi A(N+1),C(N+1);
  int sum=1;
  rep(i,0,N){
    if(S[i]=='A') A[i+1]=A[i]+sum;
    else if(S[i]=='?'){
      A[i+1]=A[i]*3+sum;
      sum*=3;
      sum%=MOD;
    }
    else A[i+1]=A[i];
    A[i+1]%=MOD;
  }
  sum=1;
  REP(i,1,N){
    int j=N-i;
    if(S[j]=='C') C[j]=C[j+1]+sum;
    else if(S[j]=='?'){
      C[j]=C[j+1]*3+sum;
      sum*=3;
      sum%=MOD;
    }
    else C[j]=C[j+1];
    C[j]%=MOD;
  }
  int ans=0;
  rep(i,0,N){
    if(S[i]=='B'||S[i]=='?'){
      ans+=A[i]*C[i+1]%MOD;
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
  }

