
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n;
  cin >> n;

  vector<int> sosuulist;
  vector<int> epi(55555+1, 0);
  for (int i = 2; i <= 55555; i++) {
    if (epi[i] == 0) {
      for (int j = i; j <= 55555; j += i) {
        epi[j] = -1;
      }
      if (i > 5 && i % 5 == 1) {
        sosuulist.push_back(i);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << sosuulist[i] << " ";
  }
  cout << endl;
}
