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
  rep(i,n) cin >> a[i];
  vector<ll> b(n);
  rep(i,n) cin >> b[i];
  vector<ll> a2(0);
  vector<ll> b2(0);
  rep(i,n){
    if(a[i]>b[i]) b2.push_back(a[i]-b[i]);
    if(a[i]<b[i]){
      if((b[i]-a[i])%2==1) a2.push_back(b[i]-a[i]-1);
      else a2.push_back(b[i]-a[i]);
    }
  }
  bool f=1;
  ll suma=0;
  rep(i,a2.size()){
    suma+=a2[i];
  }
  ll sumb=0;
  rep(i,b2.size()){
    sumb+=b2[i];
  }
  if(suma>=sumb*2){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  
}