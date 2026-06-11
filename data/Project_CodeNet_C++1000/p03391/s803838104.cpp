#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

struct P {
  int a, b;
};
P ps[200000+10];
// bool operator<(const P& p1, const P& p2) {
//   if((p1.b-p1.a) != (p2.b-p2.a)) {
//     return (p1.b-p1.a) > (p2.b-p2.a);
//   } else {
//     return p1.b > p2.b;
//   }
// }

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d", &ps[i].a, &ps[i].b);
  }
  ll sum = 0;
  const ll INF = 1e15;
  ll mini = INF;
  REP(i, n) {
    sum += ps[i].a;
    if(ps[i].a > ps[i].b) {
      mini = min(mini, ll(ps[i].b));
    }
  }
  if(mini == INF) {
    cout << 0 << endl;
  } else {
    cout << sum - mini << endl;
  }
  
  return 0;
}
