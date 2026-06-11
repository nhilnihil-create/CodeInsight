#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int f(int a, int b) {
  int c = abs(a - b);
  return min(c, 24 - c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> D(24); rep(i, 24) D[i] = 0;
  D[0] ++;
  rep(i, N) {
    int d; cin >> d;
    if(D[d] == 0) {
      D[d] ++;
      continue;
    } 
    if(D[d] != 0) {
      int d_ = (d != 0 ? 24 - d : 0);
      D[d_] ++;
    }
  }
  rep(i, 24) {
    if(D[i] >= 2) {
      cout << 0 << "\n";
      return 0;
    }
  }
  int ans = 0;
  for(int bit = 0; bit < (1<<11); bit++) {
    int ret = 12;
    rep(i, 11) {
      if((bit & (1<<i))) {
        if(D[i + 1] == 1 && D[23 - i] == 0) {
           D[i + 1] = 0; D[23 - i] = 1;
        }
      }
    }
    priority_queue<int, vector<int>, greater<int>> pque;
    pque.push(24);
    rep1(j, 23) {
      if(D[j] == 1) pque.push(j);
    }
    int p = 0;
    while(pque.size()) {
      int q = pque.top(); pque.pop();
      int ret1 = f(p, q);
      ret = min(ret, ret1);
      p = q;
    }
    ans = max(ans, ret);
    rep(j, 11) {
      if((bit & (1<<j))) {
        if(D[j + 1] == 0 && D[23 - j] == 1) {
           D[j + 1] = 1; D[23 - j] = 0;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}