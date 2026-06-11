#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;
#define MOD 1000000007LL

struct numb{
  int num;
  ll zero, one;
  numb(){}
  numb(int a, ll b, ll c){num = a; zero = b; one = c;}
};

int main(){
  ll N, K;
  cin >> N >> K;
  vi counter(40, 0);
  ll zeroans = 0LL;
  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    zeroans += A;
    for(int j = 0; j < 40; j++){
      if((A >> j) & 1) counter.at(j)++;
    }
  }
  if(K==0){
    cout << zeroans << endl;
    return 0;
  }

  vector<numb> num(40);
  ll n = 1LL;
  for(int i = 0; i < 40; i++){
    if(counter.at(i) > N/2){ //半分以上が1
      num.at(i) = numb(0, n * counter.at(i), n * (N-counter.at(i))); //理想, 0のとき, 1のとき
    }
    else{
      num.at(i) = numb(1, n * counter.at(i), n * (N-counter.at(i)));
    }
    n *= 2LL;
  }
  vi saidai(40, 0);
  int NN = 0;
  for(int i = 0; i < 40; i++){
    if((K >> i) & 1){
      NN = i;
      saidai.at(i)++;
    }
  }

  // K != 0のとき（K == 0のときはX == 0のときが答え）
  vvll dp(NN+1, vll(2, 0));
  dp.at(NN).at(0) = num.at(NN).one;
  dp.at(NN).at(1) = num.at(NN).zero;
  for(int i = NN; i >= 1; i--){
    ll x = max(num.at(i-1).zero, num.at(i-1).one);
    chmax(dp.at(i-1).at(1), dp.at(i).at(1) + x);
    if(saidai.at(i-1) == 1){
      chmax(dp.at(i-1).at(1), dp.at(i).at(0) + num.at(i-1).zero);
      chmax(dp.at(i-1).at(0), dp.at(i).at(0) + num.at(i-1).one);
    }
    else{
      chmax(dp.at(i-1).at(0), dp.at(i).at(0) + num.at(i-1).zero);
    }
  }
  ll answer = max(dp.at(0).at(0), dp.at(0).at(1));
  for(int i = NN+1; i < 40; i++){
    answer += num.at(i).zero;
  }
  cout << answer << endl;
}