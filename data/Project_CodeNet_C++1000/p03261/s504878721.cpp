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

int main(){
  ll N;
  cin >> N;
  vector<string> W(N);
  rep(i, N) cin >> W[i];
  map<string, ll> cnt;

  cnt[W[0]]++;

  rep2(i, 1, N){
    if(W[i - 1][W[i - 1].size() - 1] != W[i][0]){
      cout << "No\n";
      return 0;
    }
    if(cnt[W[i]] > 0){
      cout << "No\n";
      return 0;
    }

    cnt[W[i]]++;    
  }

  cout << "Yes\n";
  
  return 0;
}
