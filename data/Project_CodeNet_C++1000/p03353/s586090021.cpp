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
void func(string X,vector<string> &S){
  bool flag=1;
  rep(i,0,S.size()){
    if(S[i]==X){
      flag=0;
      break;
      }
    }
  if(flag){
    S[0]=X;
    rep(i,1,S.size()){
      if(S[i]>S[i-1])
        swap(S[i],S[i-1]);
      else
        break;
      }
    }
  }
signed main(){
  int K;
  string s;
  cin>>s>>K;
  vector<string> S(K,"{");
  rep(i,0,s.size()){
    REP(j,1,s.size()-i){
      string P=s.substr(i,j);
      if(S[0]>P)
        func(P,S);
      else
        break;
      }
    }
  cout<<S[0]<<endl;
  }
