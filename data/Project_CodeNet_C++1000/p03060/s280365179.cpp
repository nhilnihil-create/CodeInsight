#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

int main(){
  int N;cin>>N;
  vector<int> V(N);
  rep(i,N)cin>>V[i];
  rep(i,N){
    int c;cin>>c;V[i]-=c;
  }
  int ans = 0;
  rep(i,N){
    if(V[i]>0)ans+=V[i];
  }
  cout<<ans<<endl;
}