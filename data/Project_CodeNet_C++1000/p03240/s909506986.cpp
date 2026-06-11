#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> x(N), y(N);
  vector<ll> h(N);
  vector<pair<ll, pair<int, int> > > hh;
  REP(i, N){
    cin >> x[i] >> y[i] >> h[i];
    hh.push_back({h[i], {x[i], y[i]}});
  }
  sort(hh.begin(), hh.end());
  REP(i, 101){
    REP(j, 101){
      bool flag = true;
      ll H = abs(i-hh[N-1].second.first)+abs(j-hh[N-1].second.second)+hh[N-1].first;
      REP(k, N-1){
        if(H-abs(i-hh[k].second.first)-abs(j-hh[k].second.second) != hh[k].first){
          if(H-abs(i-hh[k].second.first)-abs(j-hh[k].second.second) < 0 && hh[k].first == 0){
            continue;
          }else{
            flag = false;
            break;
          }
        }
      }
      if(flag){
        cout << i << " " << j << " " << H << endl;
        return 0;
      }
    }
  }
}