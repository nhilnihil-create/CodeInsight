#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};


int main(){
  cout << setprecision(10);
  ll N,M;
  cin >> N >> M;
  vector<pii> v(M);
  for(int i = 0; i < M; i++){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    v.at(i) = make_pair(tmp1,tmp2);
  }
  reverse(v.begin(), v.end());

  UnionFind tree(N);

  vector<ll> ans;
  ll now = N * (N-1) / 2;
  ans.push_back(now);

  for(int i = 0; i < M; i++){
    int tmp1 = v[i].first;
    int tmp2 = v[i].second;

    if(tree.root(tmp1) != tree.root(tmp2)){
      now -= (ll)tree.size(tmp1) * (ll)tree.size(tmp2);
      tree.unionSet(tmp1,tmp2);
    }

    ans.push_back(now);
  }
  reverse(ans.begin(), ans.end());
  for(int i = 1; i < ans.size(); i++){
    cout << ans[i] << endl;
  }


}
