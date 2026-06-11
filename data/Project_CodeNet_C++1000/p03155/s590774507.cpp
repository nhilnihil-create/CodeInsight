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

int main() {
    int N, H, W;
    scanf("%d %d %d", &N, &H, &W);
    printf("%d\n", (N - H + 1) * (N - W + 1));
    return 0;
}
