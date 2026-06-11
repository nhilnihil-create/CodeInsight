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
int N;
int A[100000];
int func(int X){
  rep(i,0,N) X=X/A[i]*A[i];
  return X;
}
signed main(){
  cin>>N;
  rep(i,0,N) cin>>A[i];
  int left=0,right=INF;
  while(left+1<right){
    int mid=(left+right)/2;
    int X=func(mid);
    if(X<2) left=mid;
    else right=mid;
  }
  int ans=-1;
  if(func(right)==2) ans=right;
  if(func(left)==2) ans=left;
  cout<<ans<<endl;
  if(ans!=-1){
    left=0;
    right=INF;
    while(left+1<right){
      int mid=(left+right)/2;
      int X=func(mid);
     if(X<=2) left=mid;
      else right=mid;
    }
    int ans;
    if(func(right)==2) ans=right;
    else ans=left;
    cout<<ans<<endl;
  }
  }

