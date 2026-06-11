#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> d(h, vector<int>(w));
  rep(i,h)rep(j,w){
    cin>>d[i][j];
  }

  vector<pair<P,P>> a;
  rep(i,h)rep(j,w-1){
    if(d[i][j]%2==0) continue;
    a.push_back({{i,j},{i,j+1}});
    d[i][j]--;
    d[i][j+1]++;
  }
  rep(i,h-1){
    if(d[i][w-1]%2==0) continue;
    a.push_back({{i,w-1},{i+1,w-1}});
    d[i][w-1]--;
    d[i+1][w-1]++;
  }

  cout << a.size() << endl;
  for(auto it:a){
    cout << it.F.F+1 << " " << it.F.S+1 << " " << it.S.F+1 << " " << it.S.S+1 << endl;
  }

  return 0;
}