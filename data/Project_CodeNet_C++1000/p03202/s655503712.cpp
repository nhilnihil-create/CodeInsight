#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

bool carry(int th, stack<tuple<int,int,int>>& st) {
  int f, l, c;
  tie(f, l, c) = st.top();
  if (c <= th) return true;
  int last = l;
  while (c >= th) {
    st.pop();
    if (st.empty()) return false;
    tie(f, l, c) = st.top();
  }
  st.pop();
  if (f != l) {
    st.emplace(f, l-1, c);
  }
  st.emplace(l, l, c+1);
  st.emplace(l+1, last, 1);
  return true;
}

bool ok(int th, const vecint& v) {
  stack<tuple<int,int,int>> st;
  st.emplace(0, 0, 0);
  int n = v.size();
  REP(i,n) {
    int sf, sl, sc;
    tie(sf, sl, sc) = st.top();
    if (v[i] > sl) {
      st.emplace(sl+1, v[i], 1);
    } else {
      while (sf > v[i]) {
        st.pop();
        tie(sf, sl, sc) = st.top();
      }
      st.pop();
      if (v[i] > sf) {
        st.emplace(sf, v[i]-1, sc);
      }
      st.emplace(v[i], v[i], sc+1);
      if (!carry(th, st)) return false;
    }
  }
  while (!st.empty()) {
    int f, l, c;
    tie(f, l, c) = st.top();
    st.pop();
    if (f == 0 && c > 0) return false;
  }
  return true; 
}

int main()
{
  int n;
  cin>>n;
  vecint v(n);
  REP(i,n) cin>>v[i];
  int ge = 1 << 20;
  int lt = 0;
  while (ge - lt > 1) {
    int mid = (ge + lt) / 2;
    if (ok(mid, v)) {
      ge = mid;
    } else {
      lt = mid;
    }
  }
  cout << ge << endl;
  return 0;
}
