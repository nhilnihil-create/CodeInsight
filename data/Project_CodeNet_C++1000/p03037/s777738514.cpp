#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mod 1000000007
#define ar array
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

void init() {
  int n, m;
  cin >> n >> m;
  int lm=INT_MIN,rm=INT_MAX;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin>>l>>r;
    lm=max(lm,l);
    rm=min(rm,r);
  }
  if(rm-lm>=0) cout<<rm-lm+1<<endl;
  else cout<<0<<endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
