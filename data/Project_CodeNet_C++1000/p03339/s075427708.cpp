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
typedef long long ll;

int INF = 1e9+7;

int main(){

  int N;
  cin >> N;

  string S;
  cin >> S;

  vector<int> e_cnt(N+1, 0);
  vector<int> w_cnt(N+1, 0);

  rep(i, N){
    if(S[i] == 'E'){
      e_cnt[i+1] = e_cnt[i] + 1;
      w_cnt[i+1] = w_cnt[i];
    }else{
      e_cnt[i+1] = e_cnt[i];
      w_cnt[i+1] = w_cnt[i] + 1;
    }
  }

  int ans = INF;
  for(int i=1; i<=N; i++){
    int left = w_cnt[i-1];
    int right = e_cnt[N] - e_cnt[i];

    ans = min(ans, left + right);
  }

  cout << ans << endl;

  return 0;
}