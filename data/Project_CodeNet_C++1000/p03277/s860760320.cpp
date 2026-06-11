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

int n, a[SIZE];

bool check(int x) {
  int s[SIZE];

  s[0] = 0;
  for(int i=0;i<n;i++){
    s[i+1] = a[i] >= x ? 1 : -1;
    s[i+1] += s[i];
  }

  int num[SIZE] = {};
  int base = 1e5;

  int sum = 0;
  for(int i=1;i<=n;i++){
    num[base+s[i]]++;
    sum += s[i] >= 0;
  }

  ll res = 0;

  for(int i=0;i<n;i++){
    res += sum;

    if (s[i+1] < s[i]) {
      sum += num[base+s[i+1]];
    } else {
      sum -= num[base+s[i]];
    }

    num[base+s[i+1]]--;
    sum--;
  }

  debug(x);
  debug(res);

  return res * 2 >= (ll)n * (n-1) / 2 + n;
}

int main(){

  scanf("%d", &n);

  for(int i=0;i<n;i++){
    scanf("%d", a+i);
  }

  int l = 1, r = 1e9;

  while(l<r){
    int mid = (l+r+1) / 2;

    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  cout << l << endl;

  return 0;
}
