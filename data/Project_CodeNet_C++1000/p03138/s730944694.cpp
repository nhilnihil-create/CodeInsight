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
signed main(){
  int N,K; cin>>N>>K;
  vi A(40);
  rep(i,0,N){
    int X; cin>>X;
    bitset<40> B(X);
    rep(j,0,40){
      if(B.test(j))
        A[j]++;
    }
  }
  vi C,D,E;
  rep(i,0,(1ll<<20)){
    if(i>K)
      break;
    bitset<20> B(i);
    int sum=0;
    rep(j,0,20){
      if(B.test(j))
        sum+=(N-A[j])*(1ll<<j);
      else
        sum+=A[j]*(1ll<<j);
    }
    C.pb(sum);
  }
  D.pb(0);
  rep(k,0,(1ll<<20)){
    int i=(k<<20);
    if(i>K)
      break;
    E.pb(i);
    bitset<40> B(i);
    int sum=0;
    rep(j,20,40){
      if(B.test(j))
        sum+=(N-A[j])*(1ll<<j);
      else
        sum+=A[j]*(1ll<<j);
    }
    int X=D.size();
    D.pb(max(sum,D[X-1]));
  }
  int ans=0;
  E.pb((1ll<<60));
  rep(i,0,C.size()){
    int P=K-i;
    int Q=disup(E,P);
    ans=max(ans,C[i]+D[Q]);
  }
  cout<<ans<<endl;
  }

