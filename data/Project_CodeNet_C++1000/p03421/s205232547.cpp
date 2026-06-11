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
  int N,A,B; cin>>N>>A>>B;
  if(A+B<=N+1&&(N+A-1)/A<=B&&(N+B-1)/B<=A){
    int memo;
    REP(i,0,N){
      int X=i+(N-i+A-1)/A;
      if(X==B){
        memo=i;
        break;
      }
    }
    vi ans;
    REP(i,1,memo) ans.pb(i);
    vii C(N);
    for(int i=N;memo<i;i--){
      int X=(N-i)/A;
      C[X].pb(i);
    }
    rep(i,0,N){
      sort(ALL(C[i]));
      rep(j,0,C[i].size()) cout<<C[i][j]<<" ";
    }
    reverse(ALL(ans));
    rep(i,0,memo) cout<<ans[i]<<" ";
    cout<<endl;
  }
  else cout<<-1<<endl;
  }

