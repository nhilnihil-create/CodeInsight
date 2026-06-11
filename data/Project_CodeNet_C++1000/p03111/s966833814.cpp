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

ll N, A, B, C;

void dfs(vl leng, vl &gr, ll ind, ll &cost){
  if(ind == N){
    map<ll, ll> cnt;
    map<ll, ll> L;
    
    rep(i, N){
      cnt[gr[i]]++;
      L[gr[i]] += leng[i];
    }
    
    if((L[1] == 0) || (L[2] == 0) || (L[3] == 0)) return;

    ll val = 0;
    val += 10 * (cnt[1] + cnt[2] + cnt[3] - 3);
    val += abs(L[1] - A) + abs(L[2] - B) + abs(L[3] - C);
    cost = min(cost, val);

    return;
  }

  rep(i, 4){
    gr[ind] = i;
    dfs(leng, gr, ind + 1, cost);
    gr[ind] = 0;
  }

  return;
}

int main(){
  cin >> N >> A >> B >> C;
  vl leng(N);
  rep(i, N) cin >> leng[i];

  ll cost = (ll)pow(10, 10);
  vl gr(N, 0);

  dfs(leng, gr, 0, cost);

  cout << cost << endl;
  
  return 0;
}
