#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int MAX = 55555;
int main() {
  int n;
  cin >> n;
  
  vector<int> f(MAX+1), ans;
  for (int i = 2; i <= MAX; ++i) {
    if (f[i]) continue;
    if(i%5==1) ans.push_back(i);
    if(ans.size()==n) break;
    f[i] = i;
    for (int j = i*i; j <= MAX; j += i) {
      if (!f[j]) f[j] = i;
    }
  }
  rep(i,n) cout << ans[i] << " "; cout << endl;
}