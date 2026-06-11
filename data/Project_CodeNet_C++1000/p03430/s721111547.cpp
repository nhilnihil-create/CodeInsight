#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

const int MOD = int(1e9) + 7;

char S[305];
int tb[305][305][305];

int main()
{
    int K; scanf("%s%d", S+1, &K);
    int N = strlen(S+1);
    for(int i = 1; i <= N; i++) {
      for(int k = 0; k <= K; k++) {
        tb[i][i][k] = 1;
      }
    }
    for(int l = 2; l <= N; l++) {
      for(int i = 1, j = l; j <= N; i++, j++) {
        tb[i][j][0] = max(
          max(tb[i+1][j][0], tb[i][j-1][0]),
          tb[i+1][j-1][0] + (S[i] == S[j] ? 2 : 0)
        );
        for(int k = 1; k <= K; k++) {
          tb[i][j][k] = max(
            max(tb[i+1][j][k], tb[i][j-1][k]),
            tb[i+1][j-1][S[i] == S[j] ? k : k-1] + 2
          );
        }
      }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = i; j <= N; j++) {
        for(int k = 0; k <= K; k++) {
          ans = max(ans, tb[i][j][k]);
        }
      }
    }

    printf("%d\n", ans);

	return 0;
}