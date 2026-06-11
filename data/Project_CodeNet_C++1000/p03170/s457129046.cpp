#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 100001;

int N, K;
int a[MAX_N];
bool dp[MAX_K];

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) scanf("%d", &a[i]);
  for(int i = 1; i <= K; ++i) {
    for(int j = 0; j < N; ++j) {
      if(i < a[j]) break;
      dp[i] = dp[i] || !dp[i - a[j]];
    }
  }
  if(dp[K]) printf("First\n");
  else printf("Second\n");
  return 0;
}