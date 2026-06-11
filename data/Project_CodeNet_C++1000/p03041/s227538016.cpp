#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 100000000;
const int MAX_N = 100;
typedef pair<int , int> P;
typedef long long ll;
 
int main () {
  int N, K;
  cin >> N >> K;
  char S[N+1];
  cin >> S;
  S[K-1] += 32;
  cout << S << endl;
  return 0;
}