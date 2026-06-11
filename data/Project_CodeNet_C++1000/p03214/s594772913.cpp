#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll MOD=1e9+7;
const int INF=1<<30;

int main(){
  double N; cin >> N;
  vector<double> v(N);
  rep(i,N) cin >> v[i];
  double heikin=0;
  rep(i,N) heikin+=v[i]/N;
  vector<double> res(N);
  rep(i,N) res[i]=abs(v[i]-heikin);
  int ans=0;
  double cnt=INF;
  rep(i,N){
    if(res[i]<cnt){
      cnt=res[i];
      ans=i;
    }
  }
  cout << ans << endl;

  
}