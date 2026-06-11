#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N,Y;cin>>N>>Y;
  int ansx=-1;
  int ansy=-1;
  int ansz=-1;
  
  rep(x,N+1){
    rep(y,N+1){
      int z=N-x-y;
      if(0<=z &&z<=N){
      int total=10000*x + 5000*y + 1000*z;
      if(total==Y){
        ansx=x;
        ansy=y;
        ansz=z;
      }
      }
    }
  }
  
  cout<<ansx<<" "<<ansy<<" "<<ansz<<" "<<endl;
}