#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  map<int,int> mp1;
  rep(i,n){
    int x; cin >> x;
    mp1[x]++;
  }
  map<int,int> mp2;
  int m; cin >> m;
  rep(i,m){
    int x; cin >> x;
    mp2[x]++;
  }
  
  for(auto it:mp2){
    if(it.S > mp1[it.F]){
      cout << "NO" << ln; return 0;
    }
  }
  cout << "YES" << ln;
  return 0;
}