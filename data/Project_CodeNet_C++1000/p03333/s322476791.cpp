#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n;
pair<int, int> l[MAX_N], r[MAX_N];
bool used[MAX_N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    l[i].second = r[i].second = i;
    cin >> l[i].first >> r[i].first;
  }

  sort(l, l+n);
  reverse(l, l+n);
  sort(r, r+n);

  fill_n(used, n, false);
  int64_t d = 0;
  int ri = 0, li = 0, flag = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (flag == 0) {
      while (li < n && used[l[li].second]) li++;
      if (li >= n || l[li].first <= pos) break;
      d += l[li].first - pos;
      pos = l[li].first;
      used[l[li].second] = true;
    } else {
      while (ri < n && used[r[ri].second]) ri++;
      if (ri >= n || r[ri].first >= pos) break;
      d += pos - r[ri].first;
      pos = r[ri].first;
      used[r[ri].second] = true;
    }
    flag ^= 1;
  }
  d += abs(pos);

  fill_n(used, n, false);
  int64_t temp = 0;
  ri = 0, li = 0, flag = 1;
  pos = 0;
  for (int i = 0; i < n; i++) {
    if (flag == 0) {
      while (li < n && used[l[li].second]) li++;
      if (li >= n || l[li].first <= pos) break;
      temp += l[li].first - pos;
      pos = l[li].first;
      used[l[li].second] = true;
    } else {
      while (ri < n && used[r[ri].second]) ri++;
      if (ri >= n || r[ri].first >= pos) break;
      temp += pos - r[ri].first;
      pos = r[ri].first;
      used[r[ri].second] = true;
    }
    flag ^= 1;
  }

  d = max(d, temp+abs(pos));

  cout << d << endl;

  return 0;
}
