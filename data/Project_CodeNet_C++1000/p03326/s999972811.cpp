#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> z(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> z[i];
  }
  vector<ll> v(n);
  priority_queue<ll> q;
  rep(j,8){
    rep(i,n){
      if(j&(1<<0)) v[i]=x[i];
      else v[i]=-x[i];
      if(j&(1<<1)) v[i]+=y[i];
      else v[i]-=y[i];
      if(j&(1<<2)) v[i]+=z[i];
      else v[i]-=z[i];
    }
    sort(all(v));
    reverse(all(v));
    ll sum=0;
    rep(i,m) sum+=v[i];
    q.push(sum);
  }
  cout << q.top() << endl;
}