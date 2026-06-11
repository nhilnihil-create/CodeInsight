#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf

const int MAXN = 1050;
const int MP = 100 * 1000 * 1000;

int n;
int x[MAXN], y[MAXN];
int odd = 0, even = 0;
vector<long long> ans;
int evenStart = 0;
long long totalSum;
long long maxSum;

bool ok(long long x, long long y, long long mx) {
  return abs(x) + abs(y) <= mx;
}

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    if ((abs(x[i]) + abs(y[i])) % 2 == 0) {
      even++;
    } else {
      odd++;
    }
    maxSum = max(maxSum, 1ll * (abs(x[i]) + abs(y[i])));
  }

  if (even && odd) {
    puts("-1");
    return 0;
  }

  if (even) {
    ans.push_back(1);
    evenStart++;
    totalSum++;
  }

  long long last = 1;
  while (totalSum < maxSum) {
    ans.push_back(last);
    totalSum += last;
    last *= 2;
  }

  printf("%d\n", sz(ans));
  for (long long x : ans) {
    printf("%lld ", x);
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    string result = "";
    long long sum = totalSum;
    long long xx = x[i], yy = y[i];

    for (int j = sz(ans) - 1; j >= 0; j--) {
      sum -= ans[j];
      if (ok(xx + ans[j], yy, sum)) {
        xx += ans[j];
        result.append(1, 'L');
      } else if (ok(xx - ans[j], yy, sum)) {
        xx -= ans[j];
        result.append(1, 'R');
      } else if (ok(xx, yy + ans[j], sum)) {
        yy += ans[j];
        result.append(1, 'D'); 
      } else {
        yy -= ans[j];
        result.append(1, 'U');
      }
    }

    reverse(all(result));
    cout << result << endl;
  }

  return 0;
}
