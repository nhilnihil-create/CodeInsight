#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <list>
#include <math.h>
#include <string.h>
using namespace std;
typedef pair<int, int> P;
#define INF (1LL<<60)
#define int long long
#define ll long long
#define mod 1000000007

signed main(){

  int N;
  vector<int> a;
  int max_abs=-1, idx;
  vector<P> ans;

  cin >> N;
  for (int i = 0; i < N; i++){
    int t;
    cin >> t;
    a.push_back(t);
    if (abs(t) > max_abs){
      max_abs = abs(t);
      idx = i;
    }
  }

  int sign = (a[idx] >= 0 ? 1 : -1);
  for (int i = 0; i < N; i++){
    a[i] += a[idx];
    ans.push_back(P(idx + 1, i + 1));
  }

  if (sign > 0)
    for (int i = 0; i < N - 1; i++){
      a[i+1] += a[i];
      ans.push_back(P(i + 1, i + 2));
    }
  else
    for (int i = N - 1; i >= 1; i--){
      a[i-1] += a[i];
      ans.push_back(P(i + 1, i));
    }

  cout << ans.size() << endl;
  for (auto i = ans.begin(); i != ans.end(); i++)
    cout << i->first << " " << i->second << endl;

  return 0;
}