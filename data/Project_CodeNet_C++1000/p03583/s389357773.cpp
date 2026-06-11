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
  ll n; cin >> n;
  for(ll i=1;i<=3500;i++){
    for(ll j=1;j<=3500;j++){
      if(4*i*j-n*j-n*i==0) continue;
      if((n*i*j)%(4*i*j-n*j-n*i)!=0) continue;
      ll k=n*i*j/(4*i*j-n*j-n*i);
      if(k>=1&&k<=3500){
        cout <<i<<" "<<j<<" "<<k<< endl;
        return 0;
      }
    }
  }
  
}