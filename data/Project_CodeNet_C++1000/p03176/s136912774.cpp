#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define F first
//#define S second
#define debug(x) cout << #x << ": " << x << '\n';

#if 1

template<class T>
class SegmentTree {
public:
  SegmentTree(int size) {
    int n = 1;
    while (n < size) n <<= 1;

    int segCount = n * 2 - 1;

    maxes = vector<T>(segCount, 0);
    left = vector<int>(segCount);
    right = vector<int>(segCount);
    mp = vector<int>(segCount);
    childs = vector<pair<int, int>>(segCount);

    for (int i = 0, l = 0, w = n; i < segCount; i++) {
      left[i] = l;
      right[i] = left[i] + w;
      mp[i] = left[i] + (w >> 1);
      childs[i] = { ((i + 1) << 1) - 1, ((i + 1) << 1) };
      if (right[i] >= n) {
        w >>= 1; l = 0;
      }
      else {
        l += w;
      }
    }
  }

  void SetValue(T value, int index, int segIndex = 0) {

    if (left[segIndex] == index && index + 1 == right[segIndex]) {
      //cout << "max[" << segIndex << "] = " << value << newl;
      maxes[segIndex] = value;
      while (segIndex) {
        segIndex = ((segIndex + 1) >> 1) - 1; // parent
        if (maxes[segIndex] >= value) break;
        maxes[segIndex] = value;
        //cout << "max[" << segIndex << "] = " << value << newl;
      }
    }
    else {
      if (index < mp[segIndex]) {
        SetValue(value, index, childs[segIndex].first);
      }
      else {
        SetValue(value, index, childs[segIndex].second);
      }
    }
  }

  // [L, R)
  T GetMax(int pLeft, int pRight, int segIndex = 0) {

    //cout << "GetMax(" << pLeft << ", " << pRight << ", " << segIndex << ")" << newl;

    if (left[segIndex] == pLeft && right[segIndex] == pRight) {
      //cout << "return max[" << segIndex << "] = " << maxes[segIndex] << newl;
      return maxes[segIndex];
    }
    else {
      T result;
      if (pLeft < mp[segIndex]) {
        result = GetMax(pLeft, min(pRight, mp[segIndex]), childs[segIndex].first);
      }
      if (mp[segIndex] < pRight) {
        result = max(result, GetMax(max(pLeft, mp[segIndex]), pRight, childs[segIndex].second));
      }
      return result;
    }
  }

protected:

  vector<T> maxes;

  // 区間 [l, r) とその中間
  vector<int> left, right, mp;
  vector<pair<int, int>> childs;
  int power;
};

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  // dp[i][j] := i 番目までの花のうち、高さ j までを選んだときの最高スコア
  // dp[i][j]を計算するのに必要なのはdp[i-1][j-n]なので、dp[j]の1列だけ持てばいい

  // dp[i] := 現在処理している花までのうち、高さ i 以下の花を選んだときの最高スコア
  // 結果: TLE

  // これだと高さ h のスコアが更新されたときの処理時間が最悪 O(N) なので遅い。少し変える

  // dp[i] := 現在処理している花までのうち、高さ i 以下かつ高さ i の花を含んだ集合での最高スコア
  // 結果: TLE

  // これで更新自体の処理はO(1)になったが、高さ h 以下の最高スコアを得るのに最悪 O(N) かかってしまう
  // 一つ前の方法の方がTLEの数が少なかった

  // (ここで解説を読む)

  // 上記問題をSegment Treeが解決してくれるらしい


  vector<int> h(N), a(N);
  F0R(i, N) {
    cin >> h[i];
  }
  F0R(i, N) {
    cin >> a[i];
  }

#if 0
  // generate test data
  N = 2e5;
  h.resize(N);
  a.resize(N);
  F0R(i, N) {
    h[i] = N - i;
  }
  F0R(i, N) {
    a[i] = 1;
  }
#endif

  SegmentTree<i64> st(N+1);

  F0R(i, N) {
    i64 score = 0;
    score = st.GetMax(0, h[i]);
    //debug(score);

    score += a[i];
    st.SetValue(score, h[i]);
  }

  i64 result = st.GetMax(0, N + 1);
  cout << result;
}
#endif
