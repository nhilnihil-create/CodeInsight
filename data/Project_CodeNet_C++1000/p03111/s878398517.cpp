#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int N, A, B, C;
vector<int> kado;
int ans;

ll dfs(int cur, vector<int> comb, vector<int> &vec) {
  ll ans = INF;
  if(cur == N) {
    vector<int> conn(3, 0);
    vector<int> conn_cnt(3, 0);
    ll cost = 0;
    REP(j, N) {
      if (comb[j] > 2) {
        continue;
      }
      conn_cnt[comb[j]]++;
      conn[comb[j]] += vec[j];
    }
    REP(j, 3) {
      if (conn[j] == 0) {
        return INF;
      }
      cost += 10*(conn_cnt[j] - 1);
    }
    cost += abs(A - conn[0]);
    cost += abs(B - conn[1]);
    cost += abs(C - conn[2]);
    
    return cost;
  }
  REP(i, 4) {
    vector<int> c_comb(cur+1);
    REP(j, cur) {
        c_comb[j] = comb[j];
    }
    c_comb[cur] = i;
    ans = min(ans, dfs(cur+1, c_comb, vec));
  }
  return ans;
}

int main()
{
  cin >> N >> A >> B >> C;
  vector<int> vec(N);
  REP(i, N) {
    cin >> vec[i];
  }
  
  kado.push_back(A);
  kado.push_back(B);
  kado.push_back(C);
  kado.push_back(0);
  vector<int> comb(0);
  cout << dfs(0, comb, vec) << endl;
  return 0;
}