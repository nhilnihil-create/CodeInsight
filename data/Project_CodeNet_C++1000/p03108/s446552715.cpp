#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
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
  ll n,m;
  cin >> n >> m;
  ll ans[m+1];
  ans[m]=0;
  ll a[m];
  ll b[m];
  rep(i,m)cin >> a[i] >> b[i];
  UnionFind k(n);
  rep(i,m){
    ll c=a[m-1-i],d=b[m-1-i];
    c--;
    d--;
    if(k.findSet(c,d)){
      ans[m-1-i]=ans[m-i];
      continue;
    }
    else{
      ll o=k.size(c),p=k.size(d);
      ans[m-i-1]=ans[m-i]+o*p;
      k.unionSet(c,d);
    }
  }
  rep(i,m)cout << n*(n-1)/2-ans[i+1] << endl;
}