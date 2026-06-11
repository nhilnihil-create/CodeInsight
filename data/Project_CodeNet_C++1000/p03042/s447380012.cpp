#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 100000000;
const int MAX_N = 100;
typedef pair<int , int> P;
typedef long long ll;
 
int main () {
  string S;
  cin >> S;
  int F = (S[0] - '0') * 10 + S[1] - '0';
  int B = (S[2] - '0') * 10 + S[3] - '0';
  if (1 <= F && F <= 12 && 1 <= B && B <= 12) {
    printf("AMBIGUOUS\n");
  }
  else if ((F == 0 || 12 < F) && 1 <= B && B <= 12) {
    printf("YYMM\n");
  }
  else if (1 <= F && F <= 12 && (B == 0 || 12 < B)) {
    printf("MMYY\n");
  } else {
    printf("NA\n");
  }
  return 0;
}