#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<string> S(2*N);
  rep(i,N) cin>>S[i];
  rep(i,N) S[i]+=S[i];
  for(int i=N;i<2*N;i++) S[i]=S[i-N];

  int ans=0;
  for(int i=0;i<N;i++){
    bool ok=true;
    for(int j=i;j-i<N;j++){
      for(int k=0;k<N;k++){
        if(S[j][k]!=S[k+i][j-i]){
          ok=false;
          break;
        }
      }
    }
    if(ok)ans+=N;
  }
  cout<<ans<<endl;

  return 0;
}
