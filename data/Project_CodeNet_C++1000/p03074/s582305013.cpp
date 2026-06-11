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

int N;
int K;
string S;

int main(){
  // Input
  cin >> N >> K;
  cin >> S;

  // 圧縮
  vector<int> cnts;

  if(S[0] != '1'){
    cnts.push_back(0);
  }

  int tmp_num = S[0] - '0';
  int tmp_cnt = 1;
  for(int i=1; i<S.size(); i++){
    int tmp_digit = S[i] - '0';
    if(tmp_digit != tmp_num){
      cnts.push_back(tmp_cnt);
      tmp_num = tmp_digit;
      tmp_cnt = 1;
    }else{
      tmp_cnt++;
    }
  }
  cnts.push_back(tmp_cnt);

  // for(int i: cnts){
  //   cout << i << " ";
  // }
  // cout << endl;

  int ans = 0;

  vector<int> sum(cnts.size());
  sum[0] = cnts[0];
  for(int i=1; i<sum.size(); i++){
    sum[i] = sum[i-1] + cnts[i];
  }
  sum.push_back(sum.back());

  // for(int i: sum){
  //   cout << i << " ";
  // }
  // cout << endl;

  

  for(int i=0; i<sum.size(); i+=2){
    int left = i-1;
    int right = min((int)sum.size()-1, i+2*K);

    int tmp_ans;
    if(i == 0){
      tmp_ans = sum[right];
    }else{
      tmp_ans = sum[right] - sum[left];
    }
    ans = max(ans, tmp_ans);

    // cout << "===" << endl;
    // cout << "left:" << left << endl;
    // cout << "right:" << right << endl;
    // cout << "tmp_ans:" << tmp_ans << endl;
  }

  cout << ans << endl;



  return 0;
}
