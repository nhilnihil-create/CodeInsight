#include <bits/stdc++.h>
using namespace std;

int conv(string &sex) {
  if (sex == "Male") {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  int n;
  cin>>n;
  int seat[n+1];
  for (int i=0; i<=n; i++) seat[i] = -1;

  cout<<0<<endl<<flush;
  string o1;
  cin>>o1;
  if (o1 == "Vacant") {
    return 0;
  }
  seat[0] = conv(o1);
  seat[n] = seat[0];

  int male = 0;
  int female = 1;
  queue<pair<int, int> > que;
  que.push(make_pair(0, n));
  while (!que.empty()) {
    auto t = que.front();
    que.pop();
    int i_begin = t.first;
    int i_end = t.second;
    int begin = seat[i_begin];
    int end = seat[i_end];
    while (i_begin < i_end) {
      int i = (i_begin + i_end) / 2;
      cout<<i<<endl<<flush;
      string o;
      cin>>o;
      if (o == "Vacant") {
        return 0;
      }
      int sex = conv(o);
      seat[i] = sex;
      bool found = false;
      int prev_end = end;
      if (sex == begin && (i - i_begin) %  2 == 1) {
        i_end = i;
        end = sex;
        found = true;
      } else if (sex != begin && (i - i_begin) % 2 == 0) {
        i_end = i;
        end = sex;
        found = true;
      }
      if ((sex == prev_end) && ((i_end - i) % 2 == 1)) {
        if (!found) {
          i_begin = i;
          begin = sex;
        } else {
          que.push(make_pair(i, i_end));
        }
      } else if ((sex != prev_end) && (i_end - i) % 2 == 0) {
        if (!found) {
          i_begin = i;
          begin = sex;
        } else {
          que.push(make_pair(i, i_end));
        }
      }
    }
  }
}