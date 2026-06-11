#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  if (S[K-1] == 'A') S[K-1] = 'a';
  if (S[K-1] == 'B') S[K-1] = 'b';
  if (S[K-1] == 'C') S[K-1] = 'c';
  rep(i,N) cout << S[i];
  cout << endl;
  return 0;
}