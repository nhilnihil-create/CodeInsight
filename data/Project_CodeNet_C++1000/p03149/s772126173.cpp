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
  vector<int> v(4);
  rep(i,4){
    cin >> v[i];
  }
  sort(all(v));
  bool flag=false;
  rep(i,4){
    if(v[0]==1&&v[1]==4&&v[2]==7&&v[3]==9){
      flag=1;
    }
  }
  if(flag){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}