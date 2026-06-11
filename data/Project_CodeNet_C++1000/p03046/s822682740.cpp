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
  int M,X; cin>>M>>X;
  if(X==0) rep(i,0,(1ll<<M)) cout<<i<<" "<<i<<" ";
  else if((1ll<<M)<=X||M==1) cout<<-1<<endl;
  else{
    vector<bool> F((1ll<<M),1);
    vector<pii> A;
    rep(i,0,(1ll<<M)){
      if(F[i]){
        F[i]=0;
        int P=i^X;
        F[P]=0;
        A.pb(mp(P,i));
      }
    }
    rep(i,0,A.size()/2){
      cout<<A[i*2].first<<" "<<A[i*2].second<<" "<<A[i*2+1].first<<" "<<A[i*2+1].second<<" ";
      cout<<A[i*2].second<<" "<<A[i*2].first<<" "<<A[i*2+1].second<<" "<<A[i*2+1].first<<" ";
    }
  }
  }


