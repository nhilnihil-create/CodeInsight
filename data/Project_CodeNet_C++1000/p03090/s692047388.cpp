#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  int n;cin>>n;
  int m=n*(n+1)/2;
  int p=0;
  for(int d=2;d*d<=m;d++) {
    if (m%d==0) {
      p=d;
      break;
    }
  }
  int r[111]{};
  int s[111]{};
  vector<int> comps[111];
  int z = m/p;
  for (int i=0;i<p;i++) {
    for (int k=n;k>=1;k--) {
      if (r[k]) continue;
      if (s[i]+k > z) continue;
      s[i]+=k,comps[i].pb(k);
      r[k] = 1;
    }
  }
  vector<pii> edges;
  for (int i=0;i<p;i++){
    for(int j=i+1;j<p;j++){
      for(int u:comps[i]) for(int v:comps[j]) edges.pb({u,v});
    }
  }
  cout<<edges.size()<<endl;
  for(auto pr:edges) cout<<pr.fst<<" "<<pr.snd<<endl;
  return 0;
}
