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
  vi A(13);
  rep(i,0,N){
    int X; cin>>X;
    A[X]++;
  }
  bool flag=1;
  if(A[0]>=1) flag=0;
  rep(i,1,12){
    if(A[i]>=3) flag=0;
  }
  if(A[12]>=2) flag=0;
  int ans=0;
  if(flag){
    rep(i,0,(1ll<<11)){
      bitset<11> B(i);
      vector<bool> F(24);
      F[0]=1;
      if(A[12]==1) F[12]=1;
      rep(j,0,11){
        if(A[j+1]==2){
          F[j+1]=1;
          F[23-j]=1;
        }
        else if(A[j+1]==1){
          if(B.test(j)) F[j+1]=1;
          else F[23-j]=1;
        }
      }
      int sum=12;
      rep(j,0,24){
        REP(k,j+1,24){
          if(F[j]&&F[k]){
            sum=min({sum,k-j,24-k+j});
          }
        }
      }
      ans=max(ans,sum);
    }
  }
  cout<<ans<<endl;
  }
