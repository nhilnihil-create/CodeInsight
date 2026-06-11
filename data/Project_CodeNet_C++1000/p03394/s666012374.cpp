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
  if(N==3) cout<<2<<" "<<3<<" "<<25<<endl;
  else{
    vi A,B,C;
    REP(i,1,30000){
      if(i%6==0) A.pb(i);
      else if(i%2==0) B.pb(i);
      else if(i%3==0) C.pb(i);
    }
    cout<<B[0]<<" "<<B[1]<<" "<<C[0]<<" "<<C[1];
    N-=4;
    rep(i,1,B.size()/2){
      if(N>=2){
        N-=2;
        cout<<" "<<B[i*2]<<" "<<B[i*2+1];
      }
    }
    rep(i,1,C.size()/2){
      if(N>=2){
        N-=2;
        cout<<" "<<C[i*2]<<" "<<C[i*2+1];
      }
    }
    rep(i,0,N) cout<<" "<<A[i];
    cout<<endl;
  }
  }
