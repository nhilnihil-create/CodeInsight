#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>h(N);
  for(int i=0;i<N;i++)cin>>h[i];

  int ans=0;
  while(true){
    bool ok=true;
    for(auto it:h)if(it>0)ok=false;
    if(ok)break;

    int c=0;
    for(int i=0;i<N;i++){
      bool f=false;
      if(i==0)f=true;
      if(h[i]<=0){
        while(i+1<N&&h[i+1]<=0)i++;
        if(!f&&i!=N-1)c++;
      }
    }
    for(int i=0;i<N;i++)h[i]--;
    ans+=c+1;
  }

  cout<<ans<<endl;

  return 0;
}
