#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

const int MAXN = 1234567;
char s[MAXN];
int k[87];

LL solve(int N, int K) {
   LL cntD = 0, cntM = 0, cur = 0, nrD = 0;
   LL ans = 0, sum = 0;
   while (cur < N && cur < K - 1) {
         char c = s[cur];
         if (c == 'D') {
            nrD++;
         } else if (c == 'M') {
            cntD += nrD;
            nrD = 0;
            cntM++;
            sum += cntD;
         } else if (c == 'C') {
            ans += sum;
         }
         cur++;
   }
   while (cur < N) {
         char ft = s[cur - K], bk = s[cur];
         if (ft == 'D') {
            sum -= cntM;
            if (cntM) cntD--;
            else nrD--;
         } else if (ft == 'M') {
            cntM--;
         }
         if (bk == 'C') {
            ans += sum;
         } else if (bk == 'M') {
            cntD += nrD;
            nrD = 0;
            cntM++;
            sum += cntD;
         } else if (bk == 'D') {
            nrD++;
         }
         cur++;
   }
   return ans;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    scanf("%s", s);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) scanf("%d", &k[i]);
    for (int i = 0; i < Q; i++) {
        printf("%lld\n", solve(N, k[i]));
    }
    return 0;
}
