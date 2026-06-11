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

  string S;
  cin>>S;
  int ans=0;
  for(auto it:S){
    if(it=='+')ans++;
    else ans--;
  }
  cout<<ans<<endl;
  return 0;
}
