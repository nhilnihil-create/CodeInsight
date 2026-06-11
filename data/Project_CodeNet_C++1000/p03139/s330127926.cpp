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
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    int ans = 0;
    if (A + B >= N) ans = (A + B) - N;
    printf("%d %d\n", min(A, B), ans);
    return 0;
}
