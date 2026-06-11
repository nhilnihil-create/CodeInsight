#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

vl sum(200010);


int findMaximal(int from, int to) {
	// d[i] = a[i] - a[i-1]とする。
	// このとき、d[i] > 0 <=> a[i] > a[i-1]なので、
	// d[i] > 0なる最大のi in (from, to)を見つけると、a[i]が最大値

	return from;
}

int main() {
  int n;
  cin >> n;
  vl a(n);
  rep (i, n) {
    cin >> a[i];
  }
  rep (i, n) {
    sum[i + 1] = sum[i] + a[i];
  }
  ll ans = INF;
  for (int i = 2; i <= n - 2; i++) {
    ll sum1 = sum[i], sum2 = sum[n] - sum[i];
    int x0 = 1, x3 = i;
    /*
    while (x0 + 1 < x3) {
      int x1 = (2*x0 + x3) / 3, x2 = (x0 + 2*x3) / 3;
      ll sum11 = sum[x1], sum12 = sum1 - sum[x1];
      ll sum21 = sum[x2], sum22 = sum1 - sum[x2];
      if (abs(sum11 - sum12) >= abs(sum21 - sum22)) {
        x0 = x1;
      }
      else {
        x3 = x2;
      }
    }
    //*/
	for (;x3 - x0 > 1;) {
      int mid = (x0 + x3) / 2;
      ll sum11 = sum[mid], sum12 = sum1 - sum[mid];
      ll sum21 = sum[mid - 1], sum22 = sum1 - sum[mid - 1];
      ll u1 = abs(sum11 - sum12), u2 = abs(sum21 - sum22);
      (-u1 + u2 > 0 ? x0 : x3) = mid;
	}
    /*
    ll s0, s1;
    ll sum11 = sum[x0], sum12 = sum1 - sum[x0];
    ll sum21 = sum[x3], sum22 = sum1 - sum[x3];
    if (abs(sum11 - sum12) >= abs(sum21 - sum22)) {
      s0 = sum[x3];
      s1 = sum1 - s0;
    }
    else {
      s0 = sum[x0];
      s1 = sum1 - s0;
    }
    //*/
    
    ll s0 = sum[x0];
    ll s1 = sum1 - s0;
    x0 = i + 1, x3 = n;
    /*
    while (x0 + 1 < x3) {
      int x1 = (2*x0 + x3) / 3, x2 = (x0 + 2*x3) / 3;
      ll sum11 = sum[x1] - sum[i];
      ll sum12 = sum2 - sum11;
      ll sum21 = sum[x2] - sum[i];
      ll sum22 = sum2 - sum21;
      if (abs(sum11 - sum12) >= abs(sum21 - sum22)) {
        x0 = x1;
      }
      else {
        x3 = x2;
      }
    }
    //*/
    while (x0 + 1 < x3) {
      int mid = (x0 + x3) / 2;
      ll sum11 = sum[mid] - sum[i];
      ll sum12 = sum2 - sum11;
      ll sum21 = sum[mid - 1] - sum[i];
      ll sum22 = sum2 - sum21;
      ll u1 = abs(sum11 - sum12), u2 = abs(sum21 - sum22);
      (-u1 + u2 > 0 ? x0 : x3) = mid;
    }
    /*
    ll s2, s3;
    sum11 = sum[x0] - sum[i];
    sum12 = sum2 - sum11;
    sum21 = sum[x3] - sum[i];
    sum22 = sum2 - sum21;
    if (abs(sum11 - sum12) >= abs(sum21 - sum22)) {
      s2 = sum21;
      s3 = sum22;
    }
    else {
      s2 = sum11;
      s3 = sum12;
    }
    //*/
    ll s2 = sum[x0] - sum[i];
    ll s3 = sum2 - s2;
    ll mi = min({s0, s1, s2, s3}), ma = max({s0, s1, s2, s3});
    ans = min(ans, ma - mi);
  }
  cout << ans << endl;
}
