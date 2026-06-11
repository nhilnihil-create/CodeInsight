#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e6 + 5, LG = 19, MOD = 1e9 + 7;
const int SQ =225;
const long double EPS = 1e-7;
int n, a[200005];
bool check(int c){
  map<int, int> mp;

  f(i,1,n){
    if(a[i] <= a[i - 1]){
      while(mp.size() && mp.rbegin()->first > a[i])
        mp.erase(--mp.end());
      if(c==1)return false;
      int idx = a[i];
      while(mp[idx] == c-1){
        mp.erase(idx);
        --idx;
      }
      if(!idx)
        return false;
      mp[idx]++;
    }
  }
  return true;
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n;

  f(i,0,n)
    cin >> a[i];

  int lo = 1, hi = n;

  while(lo < hi){
    int md = lo + (hi-lo)/2;
    if(check(md))
      hi = md;
    else
      lo = md + 1;
  }

  cout << lo << endl;

  return 0;
}
