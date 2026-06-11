#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int MOD = 1e9+7;

int N, K;
vector<int> v;

ll solve(int l, int r, int d){
  ll ret = 0;
  vector<int> minus;

  int l_cnt=0;
  while(l_cnt < l){
    ret += v[l_cnt];
    if(v[l_cnt] < 0){
      minus.push_back(v[l_cnt]);
    }
    l_cnt++;
  }

  int r_cnt=0;
  while(r_cnt < r){
    ret += v[N-1-r_cnt];
    if(v[N-1-r_cnt] < 0){
      minus.push_back(v[N-1-r_cnt]);
    }
    r_cnt++;
  }

  sort(minus.begin(), minus.end());

  // cout << "===" << endl;
  // cout << "l:" << l << endl; 
  // cout << "r:" << r << endl; 
  // cout << "d:" << d << endl; 
  // rep(i, sz(minus)) cout << minus[i] << " ";
  // cout << endl;

  rep(i, min(d, sz(minus))){
    if(minus[i] < 0){
      ret -= minus[i];
    }
  }

  return ret;
}

int main(){
  cin >> N >> K;

  rep(i, N){
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  ll ans = 0;
  for(int l=0; l<=K; l++){
    for(int r=0; r<=K-l; r++){
      if(l+r > N) continue;
      int d = K - (l+r);
      ans = max(ans, solve(l, r, d));

      // cout << "ans: " << ans << endl;
    }
  }
  
  cout << ans << endl;

  return 0;
}
