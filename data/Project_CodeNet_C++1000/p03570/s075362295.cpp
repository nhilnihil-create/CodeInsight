#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

const int MAX_N = 200005;

string S;
int SBit[MAX_N];
int getBit(int l, int r) {
  return SBit[r] ^ SBit[l];
}

int DP[1 << 26];
int setDp(int index, int k) {
  if(DP[index] == -1) {
    DP[index] = k;
  } else {
    DP[index] = min(DP[index], k);
  }
}

int getDp(int index) {
  if(DP[index] == -1) {
    return MAX_N;
  } else {
    return DP[index];
  }
}

int opt[MAX_N];

int main()
{
  cin >> S;
  int N = S.length();
  for(int i = 0; i < S.length(); i++) {
    SBit[i+1] = SBit[i]^(1 << (S[i] - 'a'));
  }

  memset(DP, -1, sizeof(DP));
  
  for(int i = 0; i < MAX_N; i++) {
    opt[i] = 1145141919;
  }
  opt[0] = 0;

  setDp(0, 0);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 27; j++) {
      int K;
      if (j == 0) {
	K = 0;
      } else {
	K = (1 << (j-1));
      }
      opt[i+1] = min(opt[i+1], 1 + getDp(K ^ getBit(0, i+1)));
    }
    setDp(getBit(0, i+1), opt[i+1]);
  }

  cout << opt[N] << endl;

  return 0;
}
