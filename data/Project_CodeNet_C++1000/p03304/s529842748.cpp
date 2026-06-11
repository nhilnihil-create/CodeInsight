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
  cout << fixed << setprecision(15);
  ll n,m,d; cin >> n >> m>> d;
  if(d==0){
    cout << (double)(m-1)/n << endl;
  }
  else{
    cout << (double)(m-1)*2*(n-d)/(n*n) << endl;
  }
}