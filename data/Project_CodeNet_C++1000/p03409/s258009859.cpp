#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll N;

bool comp(pll p1, pll p2){
  if(p1.second != p2.second)
    return p1.second < p2.second;
  else
    return p1.first < p2.first;
}

int main(){
  cin >> N;
  vpll ab(N), cd(N);
  rep(i, N) cin >> ab[i].first >> ab[i].second;
  rep(i, N) cin >> cd[i].first >> cd[i].second;

  stable_sort(cd.begin(), cd.end());
  stable_sort(ab.begin(), ab.end(), comp);
  vl used(N, 0);
  ll ans = 0;

  rep(i, N){
    rep_inv(j, N - 1, -1){
      if((ab[j].first < cd[i].first) && (ab[j].second < cd[i].second) && (used[j] == 0)){
        used[j] = 1;
        ans++;
        break;
      }
    }
  }

  cout << ans << "\n";
  
  return 0;
}
