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
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  vector<ll> v(0);
  v.push_back(a*x+b*y);
  v.push_back(c*min(x,y)*2+a*(x-min(x,y))+b*(y-min(x,y)));
  v.push_back(c*max(x,y)*2);
  sort(all(v));
  cout << v[0] << endl;

}