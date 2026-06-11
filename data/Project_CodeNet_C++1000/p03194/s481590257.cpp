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
  int N,P;
  cin>>N>>P;
  int ans=1,count=0,i=3;
  if(N==1)
    ans=P;
  else{
  if(P>1){
    while(1){
      if(P%2==0){
      count++;
      P/=2;
    }
    else{
      rep(j,0,count/N)
        ans*=2;
      count=0;
      break;
    }
    }
  while(1){
    if(i*i>P)
      break;
    if(P%i==0){
      count++;
      P/=i;
    }
    else{
      rep(j,0,count/N)
        ans*=i;
      count=0;
      i+=2;
    }
  }
    rep(j,0,(count+1)/N)
        ans*=i;
  }
  }
  cout<<ans;
  }


