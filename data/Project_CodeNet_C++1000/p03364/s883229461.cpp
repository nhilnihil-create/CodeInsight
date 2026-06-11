#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF INT_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<string>S(N);
  for(int i=0;i<N;i++)cin>>S[i];
  int sum=0;
  for(int k=0;k<N;k++){
    bool ok=true;
    for(int y=0;y<N;y++){
      for(int x=0;x<N;x++){
        if(S[(y+k)%N][x]!=S[(x+k)%N][y])ok=false;
      }
    }
    sum+=ok;
  }
  if(N==1)cout<<1<<endl;
  else cout<<sum*N<<endl;
  return 0;
}
