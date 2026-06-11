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

const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<P> a;
  if(n%2){
    REP(i,1,n) a.emplace_back(i,n);
    n--;
  }
  REP(i,1,n/2)REP(j,i+1,n/2+1){
    a.emplace_back(i,j);
    a.emplace_back(i,n-j+1);
    a.emplace_back(n-i+1,j);
    a.emplace_back(n-i+1,n-j+1);
  }

  int m = a.size();
  cout << m << endl;
  rep(i,m){
    cout << a[i].F << " " << a[i].S << endl;;
  }
  return 0;
}