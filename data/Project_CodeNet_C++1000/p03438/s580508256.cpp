#pragma GCC optimize("Ofast")
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include<cmath>
#include <functional>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// --------------------------------------------------------------------------


int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  ll sum_A=0,sum_B=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum_A += A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
    sum_B += B[i];
  }
  if(sum_A > sum_B){
    cout << "No\n";
    return 0;
  }
  ll cnt = sum_B - sum_A;
  ll cnt_B=0,cnt_A=0;
  for(int i=0; i<N; i++){
    if(A[i]%2 != B[i]%2){
      cnt_B++;
      B[i]++;
    }
    if(A[i] > B[i]){
      cnt_B += A[i] - B[i];
      B[i] = A[i];
    }
    if(A[i] < B[i]){
      cnt_A += (B[i] - A[i])/2;
      A[i] = B[i];
    }
  }
  if(cnt_A <= cnt && cnt_B <= cnt){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
  return 0;
}
