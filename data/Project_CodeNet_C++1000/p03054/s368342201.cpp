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
  int H,W,N;
  cin>>H>>W>>N;
  int sx,sy;
  cin>>sx>>sy;
  string S,T;
  cin>>S;
  cin>>T;

  int up=1;
  int dw=H;
  for(int i=N-1;i>=0;i--){
    if(T[i]=='U') dw=min(H,dw+1);
    else if(T[i]=='D') up=max(1,up-1);

    if(S[i]=='U') up=up+1;
    else if(S[i]=='D') dw=dw-1;

    if(up>dw||up>H||dw<1){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(sx<up||sx>dw){
    cout<<"NO"<<endl;
    return 0;
  }

  int lef=1;
  int rig=W;
  for(int i=N-1;i>=0;i--){
    if(T[i]=='L') rig=min(W,rig+1);
    else if(T[i]=='R') lef=max(1,lef-1);

    if(S[i]=='L') lef=lef+1;
    else if(S[i]=='R') rig=rig-1;
    if(lef>rig||lef>W||rig<1){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(sy<lef||sy>rig){
    cout<<"NO"<<endl;
    return 0;
  }

  cout<<"YES"<<endl;

  return 0;
}
