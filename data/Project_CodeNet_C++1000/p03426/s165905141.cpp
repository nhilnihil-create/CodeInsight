#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i,T x=1){
    for(i++;i<=n;i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++;i>0;i -= i&-i){
      x += d[i];
    }
    return x;
  }
};

int main(){
  int h,w,d;cin >> h >> w >> d;
  map<int,int> mp;
  rep(i,h)rep(j,w){
    int a; cin >> a;--a;
    mp[a] = w*i+j;
  }
  vector<BIT<int>> tree(d,BIT<int>(h*w/d+1));
  for(int i = 0;i < h*w;i++){
    if(i/d == 0) tree[i%d].add(0,0);
    else {
      int cost = abs(mp[i]/w - mp[i-d]/w) + abs(mp[i]%w - mp[i-d]%w);
      //printf("%d %d %d %d\n",i,cost,mp[i],mp[i-d]);
      tree[i%d].add(i/d,cost);
    }
  }

  int q;cin >> q;
  rep(i,q){
    int l,r;cin >> l >>r;
    --l;--r;
    cout << tree[l%d].sum(r/d) - tree[l%d].sum(l/d) << endl;
  }

  //for(auto v:tree[0].d) cout << v << endl;

  //cout << ans << endl;
}