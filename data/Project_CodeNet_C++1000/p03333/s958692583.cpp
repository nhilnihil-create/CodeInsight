#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 7;
struct Point {
  int first, second, id;
} ;
Point d[maxn], o[maxn], Data[maxn];
 
bool cmp1(const Point &a, const Point &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
 
bool cmp2(const Point &a, const Point &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
 
bool used[maxn];
int dist(int inx, int cur) {
  if (cur >= Data[inx].first && cur <= Data[inx].second) return 0;
  if (cur < Data[inx].first) return Data[inx].first - cur;
  return cur - Data[inx].second;
}
 
int n;
long long work() {
  int t = n, h = 1;
  if (d[t].first < 0) return 0;
  for (int i = 1; i <= n; i++) used[i] = false;
  int cur = 0;
  long long rt = 0;
  for (int i = 1; i <= n; i++) {
    while (used[ d[t].id ]) t--;
    while (used[ o[h].id ]) h++;
    if (i & 1) {
      if (d[t].first >= cur) {
        rt += d[t].first - cur;
        used[ d[t].id ] = true;
        cur = d[t].first;
      }
      else break;
    }
    else {
      if (o[h].second <= cur) {
        rt += cur - o[h].second;
        used[ o[h].id ] = true;
        cur = o[h].second;
      }
      else break;
    }
  }
  return abs(cur) + rt;
}

int main(int argc, char **argv) {
  scanf("%d", &n);
 
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &d[i].first, &d[i].second);
    d[i].id = i;
    o[i] = d[i];
    Data[i] = d[i];
  }
  sort(d + 1, d + n + 1, cmp1);
  sort(o + 1, o + n + 1, cmp2);
  long long ans = work();
  for (int i = 1; i <= n; i++) {
    swap(o[i].first, o[i].second);
    o[i].first = -o[i].first;
    o[i].second = -o[i].second;
    swap(d[i].first, d[i].second);
    d[i].first = -d[i].first;
    d[i].second = -d[i].second;
  }
  sort(d + 1, d + n + 1, cmp1);
  sort(o + 1, o + n + 1, cmp2);
  ans = max(work(), ans);
 
  cout << ans << endl;
  return 0;
}