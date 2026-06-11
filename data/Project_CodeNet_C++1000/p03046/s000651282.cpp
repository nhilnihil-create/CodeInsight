#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

int test(int M, int K) {
  int arr[SIZE];

  int N = 1 << M;

  for (int i=0; i<N; i++)
    arr[i*2] = arr[i*2+1] = i;

  bool res = false;

  do{
    bool ok = true;

    for (int i=0; i<N*2; i++) {
      ll sum = 0;
      for (int j=i+1; j<N*2; j++) {
        if (arr[i] == arr[j]) {
          ok &= sum == K;
        }
        sum ^= arr[j];
      }
    }

    if (ok) {
      for (int i=0; i<N*2; i++)
        cerr << arr[i] << ", ";
      cerr << endl;
      return true;
    }

    res |= ok;

  }while(next_permutation(arr, arr+2*N));

  return res;
}

int main() {
  int M, K;

  cin >> M >> K;

  int N = 1 << M;

  if (K >= N || (M == 1 && K > 0)) {
    puts("-1");
    return 0;
  }

  if (K == 0) {
    for (int i=0; i<N; i++) {
      printf("%d %d%c", i, i, " \n"[i+1==N]);
    }
    return 0;
  }

  vector<int> ans;

  ans.push_back(K);

  for (int i=0; i<N; i++)
    if (i != K)
      ans.push_back(i);

  ans.push_back(K);

  for (int i=N-1; i>=0; i--)
    if (i != K)
      ans.push_back(i);

  for (int i=0; i<N*2; i++)
    printf("%d%c", ans[i], " \n"[i == N*2-1]);

#ifdef LOCAL
  bool ok = true;

  for (int i=0; i<N*2; i++) {
    ll sum = 0;
    for (int j=i+1; j<N*2; j++) {
      if (ans[i] == ans[j]) {
        ok &= sum == K;
      }
      sum ^= ans[j];
    }
  }

  cerr << (ok ? "OK!" : "WA...") << endl;
#endif

  return 0;
}
