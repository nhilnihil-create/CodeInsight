#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  return (a+b) % MOD;
}

int sub(int a, int b) {
  return (a-b+MOD) % MOD;
}

int mul(int a, int b) {
  return (int) (((ll) a * b) % MOD);
}

int invv(int a) {
  int r=1, e=MOD-2;
  for (; e; e/=2, a=mul(a, a))
    if (e&1) r = mul(r, a);
  return r;
}

const int MAX = 1<<19;
int p[MAX];
int n;
int pref[MAX];

int main()
{
  pref[0] = 0;
  FOR(i, 1, MAX)
    pref[i] = add(pref[i-1], invv(i));

  scanf("%d", &n);
  int sol=0;
  REP(i, n) {
    scanf("%d", &p[i]);
    sol = add(sol, mul(p[i], sub(pref[i+1], 1)));
    sol = add(sol, mul(p[i], sub(pref[n-i], 1)));
    sol = add(sol, p[i]);
  }

  FOR(i, 1, n+1) sol = mul(sol, i);
  printf("%d\n", sol);

  return 0;
}

