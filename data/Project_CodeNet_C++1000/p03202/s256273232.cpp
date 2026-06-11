#include <iostream>
#include <map>
#include <algorithm>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <queue>
#include <cstdio>
#include <stack>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

bool check(int n, const vector<int> &a, int m) {
  map<int, int> b;

  b[a[0]] = 1;

  for(int i = 1; i < n; i++){
    int next = a[i];
    const int last = (--b.end())->first;

    if(next > last) {
      b[next] = 1;
    } else {
      while(b.count(next) != 0 && b[next] == m) next--;

      if(next == 0) return false;
      if(m == 1) return false;

      b.erase(b.upper_bound(next), b.end());

      if(b[next] == 0) b[next] = 1;
      b[next] += 1;
    }

    // for(auto c : b) printf("%d=%d ", c.first, c.second); puts("");
  }

  return true;
}

int main(){
  const int n = getInt();
  vector<int> a(n);
  REP(i,n) a[i] = getInt();

  int low = 1;
  int high = n;
  while(low <= high) {
    const int med = (low + high) / 2;
    if(check(n, a, med)) {
      high = med - 1;
    } else {
      low = med + 1;
    }
    // puts("");
  }

  printf("%d\n", low);

  return 0;
}