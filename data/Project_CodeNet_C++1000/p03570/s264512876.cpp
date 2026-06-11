#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define ALL(a) (a).begin(),(a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 30);
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> Graph;
typedef vector<pii> vpii;

int v[1<<26];

int main() {
  string s; cin>>s;
  for (ll i=0;i<(1<<26);i++) v[i]=INF;
  int cur=0; v[cur]=0;
  for(char c:s) {
    c-='a';
    cur^=(1<<c);
    int mi=v[cur];
    for(int i=0;i<26;i++) {
      mi=min(mi,v[cur^(1<<i)]);
    }
    v[cur]=min(mi+1,v[cur]);
  }
  cout<<max(1,v[cur])<<endl;
}
