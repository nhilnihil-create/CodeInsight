#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
//#define INF 1e9
constexpr ll INF = 1LL << 62;
constexpr int mod = 1e9+7;

int main(){
  int K, N;
  cin >> N >> K;
  vector<ll> x(N), y(N), px(N), py(N);
  REP(i, N){
    cin >> x[i] >> y[i];
    px[i] = x[i], py[i] = y[i];
  }
  sort(px.begin(), px.end());
  sort(py.begin(), py.end());
  
  REP(i, N){
    auto itr = lower_bound(px.begin(), px.end(), x[i]);
    x[i] = itr-px.begin()+1;
    itr = lower_bound(py.begin(), py.end(), y[i]);
    y[i] = itr-py.begin()+1;
  }
  vector<vector<ll>> sum(N+1, vector<ll>(N+1, 0));
  REP(i, N){
    sum[y[i]][x[i]]++;
  }
  REP(i, N+1){
    REP(j, N){
      sum[i][j+1] += sum[i][j];
    }
  }
  REP(j, N+1){
    REP(i, N){
      sum[i+1][j] += sum[i][j];
    }
  }
  ll ans = INF;
  REP(i, N+1){
    FOR(j, i+1, N+1){
      REP(k, N+1){
        FOR(l, k+1, N+1){
          ll v = sum[j][l] - sum[j][k] - sum[i][l] + sum[i][k];
          if(v >= K){
            ll u = j-1, b = i, left = l-1, right = k;
            u = py[u], b = py[b], left = px[left], right = px[right];
            ll S = (u-b) * (left-right);
            ans = min(ans, S);
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
