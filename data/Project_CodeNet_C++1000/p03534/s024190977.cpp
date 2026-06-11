#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAX_N (100000)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  char S[MAX_N + 1];
  scanf("%s", S);
  const int N = strlen(S);

  // solve
  int cnts[3] = {};
  for (int i = 0; i < N; i++) {
    cnts[S[i] - 'a']++;
  }
  if (abs(cnts[0] - cnts[1]) <= 1 && abs(cnts[1] - cnts[2]) <= 1 &&
      abs(cnts[2] - cnts[0]) <= 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
