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
  int N,ans=0; cin>>N;
  int a=0,b=0,c=0;
  rep(_,0,N){
    string S; cin>>S;
    rep(i,1,S.size()){
      if(S[i]=='B'&&S[i-1]=='A')
        ans++;
    }
    if(S[S.size()-1]=='A'){
      if(S[0]=='B')
        c++;
      a++;
    }
    if(S[0]=='B')
      b++;
  }
  int K=min(a,b);
  if(a==b&&b==c)
    K--;
  K=max(K,0LL);
  cout<<ans+K<<endl;
  }


