#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N;
  cin>>N;
  char S[2*N][2*N];
  REP(i,N)REP(j,N)cin>>S[i][j];
  REP(i,N)REP(j,N)S[i+N][j]=S[i][j];
  REP(i,N)REP(j,N)S[i][j+N]=S[i][j];
  REP(i,N)REP(j,N)S[i+N][j+N]=S[i][j];
  lint ans=0;
  REP(B,N){
    bool f=true;
    REP(i,N)FOR(j,i,N){
      if(S[i][j+B]!=S[j][i+B])f=false;
    }
    ans+=f;
  }
  ans*=N;
  cout<<ans<<endl;
  return 0;
}
