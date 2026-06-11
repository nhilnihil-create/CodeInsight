#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 234567;
int A[MAXN], B[MAXN];

int main() {
    int N;
    while (~scanf("%d", &N)) {
          LL sum = 0;
          vector<int> ans;
          for (int i = 0; i < N; i++) {
              scanf("%d %d", &A[i], &B[i]);
              if (A[i] > B[i]) ans.push_back(B[i]);
              sum += A[i];
          }
          sort(ans.begin(), ans.end());
          if (ans.empty()) puts("0");
          else printf("%lld\n", sum - ans[0]);
    }
    return 0;
}
//1: 9346436444504
//2: 9394505453297
