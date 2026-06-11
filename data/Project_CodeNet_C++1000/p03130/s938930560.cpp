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
  vi C(4);
  string ans="YES";
  rep(i,0,3){
    int A,B; cin>>A>>B;
    C[A-1]++;
    C[B-1]++;
  }
  rep(i,0,4){
    if(C[i]<1||C[i]>2){
      ans="NO";
      break;
    }
  }
  cout<<ans<<endl;
  }
