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
  string S,T; cin>>S>>T;
  map<int,char> m;
  int X=N*M/__gcd(N,M);
  rep(i,0,N) m[X/N*i+1]=S[i];
  int ans=X;
  rep(i,0,M){
    int Y=X/M*i+1;
    if(m.count(Y)&&m[Y]!=T[i]){
      ans=-1;
      break;
    }
  }
  cout<<ans<<endl;
  }

