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
int a[MAXN], tmpa[MAXN];
vector<int> b[29];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        for (int j = 0; j <= 28; j++) {
            b[j].push_back(tmp % (1 << (j + 1)));
        }
    }
    for (int j = 0; j <= 28; j++)
        sort(b[j].begin(), b[j].end());
    int sum = 0;
    for (int j = 0; j <= 28; j++) {
        int lw1 = 0, up1 = 0, lw2 = 0;
        int K = (1 << j);
        for (int i = 0; i < N; i++) tmpa[i] = a[i] % (2 * K);
        sort(tmpa, tmpa + N);
        int cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            while (lw1 < N && tmpa[i] + b[j][lw1] < K) lw1++;
            while (up1 < N && tmpa[i] + b[j][up1] < 2 * K) up1++;
            while (lw2 < N && tmpa[i] + b[j][lw2] < 3 * K) lw2++;
            cnt += N - lw2 + up1 - lw1;
            cnt %= 2;
        }
        if (cnt) sum += (1 << j);
    }
    printf("%d\n", sum);
    return 0;
}
