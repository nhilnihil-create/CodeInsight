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

vector<int64_t>divisor(int64_t n) {
  vector<int64_t>ret;
  for(int64_t i=1;i*i<=n;i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i!=n)ret.push_back(n/i);
    }
  }
  sort(begin(ret),end(ret));
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64_t N,M;
  cin>>N>>M;
  auto v=divisor(M);
  int64_t ans=1;
  for(auto it:v){
    if(N<=M/it)ans=max(ans,it);
  }
  cout<<ans<<endl;
  return 0;
}
