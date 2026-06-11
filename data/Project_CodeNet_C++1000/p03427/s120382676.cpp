#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
int INF = 1e9+7;
// const long long INF = 1LL<<60;


int main(){
  string str;
  cin >> str;
  vector<int> nums(64);
  reverse(str.begin(), str.end());

  ll N = 0;
  ll N2 = 0;

  int not_zero = 0;
  int first_nine = -1;
  bool lasting = true;

  // cout << "str:" << str << endl;

  ll mul = 1;
  rep(i, str.size()){
    nums[i] = str[i] - '0';
    if(nums[i] != 0){
      not_zero = i;
    }
    if(nums[i] == 9 && lasting){
      first_nine = i;
    }
    if(nums[i] != 9){
      lasting = false;
    }

    N += nums[i];
    N2 += nums[i] * 10;
    mul *= 10;
  }

  if(N2<10){
    cout << N2 << endl;
    return 0;
  }

  if(not_zero - first_nine <= 1){
    cout << N << endl;
    return 0;
  }else{
    int ans = nums[not_zero] - 1;
    ans += 9 * not_zero;
    cout << ans << endl;
    return 0;
  }



  return 0;
}
