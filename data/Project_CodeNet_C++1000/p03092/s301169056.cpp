#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

/* Starry Sky Tree */
//0-index

struct StarrySkyTree{
  typedef ll Type;
  int segn2;
  vector<Type> data, s_data;
  function<Type(Type, Type)> merge;

  StarrySkyTree(function<Type(Type, Type)> merge, int n): merge(merge)
  {
    for(segn2=1; segn2<n; segn2*=2);
    data.assign(segn2*2, 0);
    s_data.assign(segn2*2, 0);
  }

  StarrySkyTree(int n): //Original Ver.
    StarrySkyTree([](Type a, Type b){ return min(a, b); }, n) {}

  //get value of [a,b)
  Type query(int a, int b, int l = 0, int r = -1, int k = 0){
    if(r == -1) r = segn2;
    if(r <= a || b <= l) return LLINF; //大きさに注意
    if(a <= l && r <= b) return data[k] + s_data[k];
    return min(query(a, b, l, (l+r)/2, k*2+1), query(a, b, (l+r)/2 , r, k*2+2)) + s_data[k];
  }

  //add x to [a,b)
  Type add(int a, int b, Type x, int l = 0, int r = -1, int k = 0){
    if(r == -1) r = segn2;
    if(a <= l && r <= b)
      s_data[k] += x;
    else if(a < r && l < b)
      data[k] = min(add(a, b, x, l, (l+r)/2, k*2+1), add(a, b, x, (l+r)/2, r, k*2+2));

    return data[k] + s_data[k];
  }

  Type val(int x){
    Type res = 0;
    x += segn2 - 1;

    while(x){
      res += s_data[x];
      x = (x-1)/2;
    }

    return res;
  }

  void add(int a, Type x){
    a += segn2 - 1;
    s_data[a] += x;

    while(a){
      a = (a-1)/2;
      data[a] = min(data[a*2+1] + s_data[a*2+1], data[a*2+2] + s_data[a*2+2]);
    }
  }
};

int main(){
  int N, A, B, p;

  scanf("%d%d%d", &N, &A, &B);

  StarrySkyTree seg(N+1);

  for(int i=0;i<N;i++){
    scanf("%d", &p);
    ll minVal = seg.query(0, p);

    seg.add(0, p, A);
    seg.add(p+1, N+1, B);

    ll q = seg.val(p);
    seg.add(p, minVal - q);
  }

  ll ans = seg.query(0, N+1);

  cout << ans << endl;

  return 0;
}
