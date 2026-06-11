#include <cstdio>
#include <iterator>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int MAXN = 234567;
int a[MAXN];

bool check(int N, int ans) {
     stack<pii> stk;
     for (int i = 1; i < N; i++) {
         if (a[i] > a[i - 1]) continue;
         if (ans == 1) return false;
         int cur = a[i], cnt = 1;
         while (!stk.empty() && stk.top().first > cur) stk.pop();
         while (!stk.empty() && (stk.top().first == cur && stk.top().second == ans)) {
               cur--;
               stk.pop();
         }
         if (cur == 0) return false;
         if (stk.empty() || stk.top().first < cur) stk.push(make_pair(cur, 2));
         else {
            cnt += stk.top().second;
            stk.pop();
            stk.push(make_pair(cur, cnt));
         }
     }
     return true;
}

int main() {
    int N;
    //freopen("in20.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = (int)2e5 + 1;
    while (l < r) {
          int mid = (l + r) / 2;
          if (check(N, mid)) {
             r = mid;
          } else {
             l = mid + 1;
          }
    }
    printf("%d\n", l);
    return 0;
}
//in06 ans: 4
//in20 ans: 50
