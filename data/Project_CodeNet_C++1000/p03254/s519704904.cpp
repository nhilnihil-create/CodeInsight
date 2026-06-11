#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
 
using namespace std;

int main() {
  int N, x; cin >> N >> x;
  vector<int> a(N);
  for (auto &i : a) cin >> i;
  
  sort(a.begin(), a.end());
  
  int ans = 0;
  for (int i=0; i<N; i++) {
    x -= a[i];
    if (x < 0) break;
    else ans++;
  }
  if (x > 0) ans--;
  cout << ans << endl;
}