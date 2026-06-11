#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
using Tu = tuple<int, int, int, int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> def(3); rep(i, 3) cin >> def[i];

  vector<int> ary(n); rep(i, n) cin >> ary[i];
  stack<pair<vector<int>, int> > s;
  vector<int> v(0);
  s.push(make_pair(v, 0));
  
  int ans = 1e9;
  while(!s.empty()) {
    pair<vector<int>, int> p = s.top(); s.pop();

    if(p.second == n) {
      vector<int> cnt(3, 0), tree = p.first;
      int cost = 0;
      int add_cnt = 0;
      rep(i, n) {
	if(tree[i] != 3) {
	  cnt[tree[i]] += ary[i];
	  cost += 10;
	  ++add_cnt;
	}
      }
      
      if(cnt[0] && cnt[1] && cnt[2]) {
	rep(i, 3) {
	  cost += abs(cnt[i] - def[i]);
	}
	
	cost = max(cost-30, 0);
	ans = min(ans, cost);
      }
    }

    if(p.second < n) {
      rep(i, 4) {
	vector<int> nv = p.first;
	nv.emplace_back(i);
	s.push(make_pair(nv, p.second+1));
      }
    }
  }
  cout << ans << endl;
}

    
