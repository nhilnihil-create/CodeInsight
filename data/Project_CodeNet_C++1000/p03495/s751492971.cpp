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
  ll N, K;
  cin >> N >> K;
  ll A;
  vl cnt(N, 0);
  rep(i, N){
    cin >> A;
    cnt[A - 1]++;
  }

  stable_sort(cnt.begin(), cnt.end(), greater<ll>());

  ll sum = 0;
  rep(i, K) sum += cnt[i];

  cout << N - sum << endl;
  
  return 0;
}
