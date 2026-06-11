#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 400000;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int BASE = 1000000000;


int main()
{
  int n;
  cin >> n;

  Int res = 0;
  Int mn = LINF;
  FOR (i,0,n)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    res += a;
    if (a > b) mn = min(mn, 1LL * b);
  }

  if (mn == LINF) res = 0;
  else res -= mn;

  cout << res << endl;
 
  return 0;
}
