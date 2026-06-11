#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <complex>
#define REP(i,a) for(int i=0;i<(a);i++)
#define REPR(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using vs = vector<string>;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

int main() {
  int A=si(), B=si(), C=si();
  if (A==B && B==C) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
