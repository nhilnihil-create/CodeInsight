#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define foru(i, l, r) for(int i = (l); i <= (r); ++i)
#define ford(i, l, r) for(int i = (l); i >= (r); --i)

#define maxn 30010

int n;
bool mark[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
    cin >> n;
    if (n == 3) {
      cout << "2 5 63";
      return 0;
    }
    vector<int> ans;
    vector<int> div6, div21, div22, div3;

    for (int i = 2; i <= 30000; ++i) {
      if (i % 6 == 0) div6.push_back(i);
      if (i % 2 == 0) {
        if (i % 3 == 1) div21.push_back(i);
        if (i % 3 == 2) div22.push_back(i);
      } else {
        if (i % 3 == 0) div3.push_back(i);
      }
    }
    int cnt = 0;
    ans.push_back(2); ans.push_back(3);
    ans.push_back(4); ans.push_back(9);
    n -= 4;

    int j = 2;
    while (cnt + 2 <= n) {
      if (j + 1 >= div3.size()) break;
      ans.push_back(div3[j]);
      ++j;
      ans.push_back(div3[j]);
      ++j;
      cnt += 2;
    }

    j = 1;
    while (cnt + 2 <= n) {
      if (j == div21.size() || j == div22.size()) break;
      ans.push_back(div21[j]);
      ans.push_back(div22[j]);
      ++j; cnt += 2;
    }

    j = 0;
    while (cnt + 1 <= n) {
      ans.push_back(div6[j]);
      ++j;
      ++cnt;
    }
    for (auto x : ans) cout << x <<' ';
    return 0;
}
