#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;
int main() {
  int N;
  cin >> N;
  int X[N];
  map_t a;
  map<int,int> b;
  for (int i = 0; i < N; i++) {
    cin >> X[i];
    a.insert(make_pair(X[i],++b[X[i]]));
  }
  for (int i = 0; i < N; i++) {
    a.erase(make_pair(X[i],b[X[i]]));
    cout << a.find_by_order(N/2-1)->first << endl;
    a.insert(make_pair(X[i],b[X[i]]));
  }
}