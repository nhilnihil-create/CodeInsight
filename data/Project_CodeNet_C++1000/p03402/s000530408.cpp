#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int a,b;
const int mx = 100;
const int h=mx,w=mx;
char g[h][w];

int main() {
  IOS;
  cin >> a >> b;
  a--; b--;

  REP(i,h) {
    char c = i<h/2 ? '#' : '.';
    REP(j,w) g[i][j] = c;
  }

  int swaped = 0;
  for (int i = 0; i < h; i+=2) {
    if (h/2 < i) {
      if (swaped == 0) {
        swap(a,b);
        swaped = 1;
      }
    }
    for (int j = 0; j < w; j+=2) {
      if (a>0) {
        g[i][j] = g[i][j] == '.' ? '#' : '.';
        a--;
      }
    }
  }

  cout << h << " " << w << endl;
  REP(i,h) REP(j,w) {
    cout << g[i][j];
    j == w-1 && cout << endl;
  }
  return 0;
}