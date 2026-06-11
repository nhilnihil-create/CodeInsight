#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* priority_queue */
template<class T>
using pq = priority_queue<T>;
template<class T>
using greatpq = priority_queue<T,vector<T>,greater<T>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define all(v) (v).begin(), (v).end()

int main(){
  int N,M;cin>>N>>M;
  vector<pll> XY;
  for(int i=0; i<N; i++){
    int a;cin>>a;
    XY.push_back({1,a});
  }
  for(int i=0; i<M; i++){
    int b,c;cin>>b>>c;
    XY.push_back({b,c});
  }
  sort(all(XY), [](pll a, pll b){
    return a.second>b.second;
  });

  ll ans = 0;
  for(pll x: XY){
    int times = x.first;
    if(times>N)times=N;
    ans += x.second*times;
    N-=times;
    if(N==0)break;
  }
  cout<<ans<<endl;
}