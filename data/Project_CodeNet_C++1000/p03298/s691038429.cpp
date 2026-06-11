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
  string S; cin>>S;
  map<pair<string,string>,int> M;
  rep(i,0,(1ll<<N)){
    bitset<18> B(i);
    string T,U;
    rep(j,0,N){
      if(B.test(j)) T+=S[j];
      else U+=S[j];
    }
    M[mp(T,U)]++;
  }
  int ans=0;
  rep(i,0,(1ll<<N)){
    bitset<18> B(i);
    string T,U;
    rep(j,0,N){
      if(B.test(j)) T+=S[j+N];
      else U+=S[j+N];
    }
    reverse(ALL(T));
    reverse(ALL(U));
    ans+=M[mp(T,U)];
  }
  cout<<ans<<endl;
  }


