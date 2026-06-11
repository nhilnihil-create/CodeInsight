#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
const int N = 100001;
struct Fenwick{
  vector<int> tree;
  Fenwick(){}
  Fenwick(int n){
    tree.resize(n + 100005);
  }
  int get(int in){
    in += 100000;
    in++;
    int res = 0;
    while(in){
      res += tree[in];
      in -= in & -in;
    }
    return res;
  }
  void add(int in, int v){
//    cout << in << ' ' << v << endl;
    in += 100000;
    in++;
    while(in < tree.size()){
      tree[in] += v;
      in += in & -in;
    }
  }

};
int a[N];
ll count_ge(int x){
  ll res = 0;
  int b[n + 1];
  b[0] = 0;
  for(int i = 0;i < n;i++){
    b[i + 1] = (a[i] >= x ? 1 : -1);
//    cout << b[i + 1] << endl;
  }
  for(int i = 1;i <= n;i++)
    b[i] += b[i - 1];
  Fenwick bt(n);
  bt.add(0, 1);
  for(int i = 1;i <= n;i++){
    res += bt.get(b[i]);
//    cout << bt.get(b[i]) << ' ' << b[i] << endl;
    bt.add(b[i], 1);
  }
  return res;
}
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  for(int i = 0;i < n;i++)
    cin >> a[i];
  int lo = 0, hi = 1000000000;
//  cout << count_ge(30) << endl;
//  return 0;
  //largest number x such that c >= x, c >= (n) * (n + 1) / 4 + 1;
  while(lo < hi){
    int mid = (lo + hi + 1) / 2;
    if(count_ge(mid) >= (1LL * n * (n + 1) / 2 + 1) / 2){
      lo = mid;
    }else{
      hi = mid - 1;
    }
  }
  cout << lo;
  return 0;
}
