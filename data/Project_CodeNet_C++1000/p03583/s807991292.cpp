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
signed main(){
  int N; cin>>N;
  REP(A,1,3500){
    REP(B,1,3500){
      int P=(4*A*B-N*A-N*B);
      if(P==0)
        continue;
      int C=N*A*B/P;
      if(C>0&&A*B*C*4==N*(A*B+C*A+B*C)){
        cout<<A<<" "<<B<<" "<<C<<endl;
        goto XYZ;
        }
      } 
    }
  XYZ:;
  }
