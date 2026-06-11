#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){

  int h,w,d;
  cin >> h >> w >> d;
  vector<P> v(h*w+1);
  REP(i,h){
    REP(j,w){
      int x;cin >> x;
      v[x] = make_pair(i,j);
    }
  }
  vector<ll> s(h*w+1);
  REP(i,d+1)s[i] = 0;
  for(int i = d+1;i <= h*w;i++){
    s[i] = s[i-d] + abs(v[i].first-v[i-d].first) + abs(v[i].second-v[i-d].second);
  }
  int Q;
  cin >> Q;
  REP(i,Q){
    int l,r;cin >> l >> r;
    cout << s[r]-s[l] << endl;
  }

  





  return 0;
}