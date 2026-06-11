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
ll mod = 1e9+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}


const double PI=3.14159265358979323846;

int N, K;

int one_side_ans(vector<int> minus, vector<int> plus){
  int L = sz(minus);
  int R = sz(plus);

  if(L==0){
    return plus[K-1];
  }

  if(R==0){
    return minus[K-1];
  }

  int ret = 1e9;
  
  int minus_s = min(L, K);

  // Lから0こ取る場合
  if(R >= K){
    ret = min(ret, plus[K-1]);
  }

  // Lから１個以上取る場合
  for(int l=minus_s; l>=0; --l){
    // check
    int rest_r = K - l;
    if(rest_r > R){
      break;
    }

    // Lからl個(折返し), Rから(K-l)個取る
    int tmp_ret = minus[l-1] * 2 + plus[rest_r-1];

    ret = min(ret, tmp_ret);
  }


  return ret;
}

int main(){
  cin >> N >> K;
  vector<int> minus;
  vector<int> plus;
  rep(i, N){
    int tmp;
    cin >> tmp;
    if(tmp == 0){
      K--;
    }else if(tmp < 0){
      minus.push_back(-tmp);
    }else{
      plus.push_back(tmp);
    }
  }

  if(K==0){
    cout << 0 << endl;
    return 0;
  }

  sort(minus.begin(), minus.end());

  int ans = 1e9;
  ans = min(ans, one_side_ans(minus, plus));
  ans = min(ans, one_side_ans(plus, minus));

  cout << ans << endl;

  return 0;
}
