#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<deque>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<tuple>
#include<utility>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvi;

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define REP(i, n)  for(int i=0; i<(int)(n); i++)
#define REPS(i, n)  for(int i=1; i<=(int)(n); i++)
#define PER(i, n) for(int i=(int)(n)-1; i>= 0; i--)
#define PERS(i, n)  for(int i=(int)(n); i>0; i--)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
#define RFOR(i, c)  for(__typeof((c).rbegin()) i=(c).rbegin(); i!=(c).end(); i++)
#define ALL(container)  (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) (container).size()
#define FILL0(n)  setfill('0') << right << setw(n)
#define mp(a, b)  make_pair(a, b)
#define toLower(c)  c+0x20
#define toUpper(c)  c-0x20
#define pb  push_back
#define eb  emplace_back

const int INF = 1e9;
const long long LLINF = 1e18;
const ll MOD = 1000000007;
const int MSIZE = 100007;
const double Pi = 3.14159265358979323146;

int main(){
  int dy[2]={0, 1};
  int dx[2]={1, 0};
  int h, w; cin >> h >> w;
  vector<vi> vec(h, vi(w));
  vi cy, cx, cny, cnx;
  REP(y, h) REP(x, w){
    cin >> vec[y][x];
  }
  int cnt=0;
  REP(y, h) REP(x, w){
    if(vec[y][x]%2==0)  continue;
    bool find=false;
    REP(i, 2){
      int ny = y+dy[i];
      int nx = x+dx[i];
      if(ny<0 || ny>=h || nx<0 || nx>=w)  continue;
      vec[y][x]--;
      vec[ny][nx]++;
      cnt++;
      cy.pb(y);
      cx.pb(x);
      cny.pb(ny);
      cnx.pb(nx);
      break;
    }
  }
  cout << cnt << endl;
  REP(i, cnt){
    cout << cy[i]+1 << " " << cx[i]+1 << " " << cny[i]+1 << " " << cnx[i]+1 << endl;
  }
}
