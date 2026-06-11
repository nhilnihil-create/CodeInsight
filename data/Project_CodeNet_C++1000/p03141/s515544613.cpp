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
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> v(n);
  ll ans=0;
  rep(i,n){
    cin >> a[i] >> b[i];
    v[i]=a[i]+b[i];
    ans-=b[i];
  }
  sort(all(v));
  int i=0;
  while(v.size()){
    if(i%2==0) ans+=v[v.size()-1];
    v.pop_back();
    i++;
  }
  cout << ans << endl;
  
}