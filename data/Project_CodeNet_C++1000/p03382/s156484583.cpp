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
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  reverse(all(a));
  ll mn=inf; int ans;
  for(int i=1;i<n;i++){
    if(abs(a[i]-(double)a[0]/2)<mn){
      mn=abs(a[i]-(double)a[0]/2);
      ans=a[i];
    }
  }
  cout << a[0] << " " << ans << endl;
}