#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC098 D = Xor Sum2
// 2020.06.19
// 「条件を満たす区間の部分区間も条件満たす」
// しゃくとり法、尺取法
// 組の個数
// 演算子の優先順位　^ よりも == の方が上 

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }

  int right = 0;
  ll res = 0;
  ll s = 0; // sは和
  for(int left = 0; left < N; left++){ // Nは要素数
    // rightの位置決め
    while(right < N && (s^A[right]) == (s+A[right])){
      s += A[right]; // 実際にrightを1進めたときの処理
      right++;
    }
  
    // whileループをbreakした後(rightは条件を満たす最大)に行う処理
    res += (right - left); // 要素の長さを足すことで組数を求めている
  
    // leftをインクリメントする準備
    if(right == left) right++;
    else s -= A[left];
  }

  cout << res <<endl;
}