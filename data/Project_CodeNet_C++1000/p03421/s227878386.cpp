#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  ll N,A,B; cin>>N>>A>>B;
  if(N<A+B-1||N>A*B){
    cout<<-1<<endl;
    return 0;
  }
  int s=1, rest=N,loop=B;
  rep(i,A){
    vector<int> tmp;
    rep(j,loop) tmp.push_back(s++);
    int n=tmp.size();
    rep(j,n) cout<<tmp[n-1-j]<<" ";
    rest-=loop;
    if(rest-(A-(i+1))<B){
      loop=rest-(A-(i+1))+1;
    }
  }
  cout<<endl;
  return 0;
}
