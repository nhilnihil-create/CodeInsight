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

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

int main() {
  int n;
  cin >> n;
  rep(i,1000){
    int res = i*(i-1)/2;
    if(n!=res) continue;
    cout << "Yes" << endl;
    cout << i << endl;
    vector<int> v[i];
    int cnt=1;
    rep(j,i)REP(k,j+1,i){
      v[j].emplace_back(cnt);
      v[k].emplace_back(cnt);
      cnt++;
    }
    rep(j,i){
      cout << v[j].size() << " ";
      for(auto it:v[j]) cout << it << " ";
      cout << endl;
    }
    return 0;
  }

  cout << "No" << endl;
  return 0;
}