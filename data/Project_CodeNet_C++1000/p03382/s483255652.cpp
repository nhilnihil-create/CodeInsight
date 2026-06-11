#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back

const int maxn = 1e5+1;
int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  auto it = max_element(a+1, a+1+n);
  int base = *it;
  int mid = (base+1)/2;
  *it = 0;
  int ans=0;
  for (int i = 1; i <= n; ++i)
    {
      if (abs(mid-a[i]) < abs(mid-ans))
	ans = a[i];
    }
  printf("%d %d\n", base, ans);

}
