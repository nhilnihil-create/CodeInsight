#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
//#include <deque>
//#include <bitset>
#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

struct BM {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  BM(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int max_match() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

int main(){
	ll n ; cin >> n ;
	vector<pll> a(n),b(n) ;
	for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second ;
	for(int i=0;i<n;i++) cin >> b[i].first >> b[i].second ;
	static BM bm(n*2) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i].first<b[j].first&&a[i].second<b[j].second){
				bm.add_edge(i,j+n) ;
			}
		}
	}
	cout << bm.max_match() << endl ;
}
