#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

/*
int h,w,d,q;
int a[301][301];
int l[90010],r[90010];
int s[90010];
vector<P> p(90010);
*/

int H,W,D,y[90001],x[90001],d[90001];
int main() {
  /*
  cin >> h >> w >> d;
  REP(i,h) REP(j,w) cin >> a[i][j];
  cin >> q;
  REP(i,q) cin >> l[i] >> r[i];

  REP(i,h) REP(j,w) p[a[i][j]] = {i,j};

  for (int i=1; i<=h*w-d; i++) {
    s[i+d] = s[i] + abs(p[i+d].first - p[i].first) + abs(p[i+d].second - p[i].second);
  }

  REP(i,q) COUT(s[r[i]] - s[l[i]]);
  return 0;
  */
	cin>>H>>W>>D;
	REP(i,H)
		REP(j,W){
			int A;
			cin>>A;
			y[A]=i,x[A]=j;
		}
	for(int i=D+1;i<=H*W;i++)
		d[i]=d[i-D]+abs(x[i-D]-x[i])+abs(y[i-D]-y[i]);
	cin>>D;
	REP(i,D){
		cin>>H>>W;
		cout<<d[W]-d[H]<<endl;
	}
}