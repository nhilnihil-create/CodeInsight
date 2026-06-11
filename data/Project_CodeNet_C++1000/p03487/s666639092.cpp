#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  rep(i,0,n) {
    int ai;
    cin >> ai;
    a[ai]++;
  }
  int k = 0;
  for (auto i = a.begin(); i != a.end(); ++i) {
    int p = i->first, q = i->second;
    if (p > q) k += q;
    else k += q - p;
  }
  cout << k << endl;
  return 0;
}