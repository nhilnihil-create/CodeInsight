#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<int, int> > vr, vb;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    vr.push_back(make_pair(b, a));
  }

  rep(i, 0, n) {
    int c, d;
    cin >> c >> d;
    vb.push_back(make_pair(c, d));
  }

  vsort(vr);
  vsort(vb);

  int rsl = 0;
  for(int i = n - 1; i >= 0; --i) {
    for(int j = 0; j < n; ++j) {
      if(vr[i].second < vb[j].first && vr[i].first < vb[j].second) {
        ++rsl;
        vb[j].first = -1;
        vb[j].second = -1;
        break;
      }
    }
  }
  cout << rsl << endl;
}
