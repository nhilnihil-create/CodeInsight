#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main() {
  int n,m,c; cin>>n>>m>>c;
  int a[m],b[m],cnt=0; 
  REP(i,m) cin>>b[i];
  REP(i,n){
    int sum=0;
    REP(j,m){
      cin>>a[j];
      sum+=a[j]*b[j];
    }
    if(sum+c>0) cnt++;
  }
  cout<<cnt<<endl;
}