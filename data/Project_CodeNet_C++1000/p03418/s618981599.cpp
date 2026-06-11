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
  lint N,K;
  cin>>N>>K;
  lint ans=0;
  if(K==0){
    cout<<N*N<<endl;
    return 0;
  }
  FOR(b,K+1,N+1){
    ans+=(N/b)*(b-K)+max(0LL,N%b-K+1);
  }
  cout<<ans<<endl;
  return 0;
}
