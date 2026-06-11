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
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n;
  cin >> n;
  vi a(n);
  int cnt = 0;
  for (int &i : a)
    cin >> i;
  vi b(all(a));
  for (int i = 0; i < n; i++)
    b[i] = b[i] - (i + 1);
  sort(all(b));
int  med = b[ (n-1) / 2];
// cout<<med<<endl;
int ans=0;
for(int i=0;i<n;i++){
  ans+=(abs(a[i]-(med+i+1)));
}
cout<<ans<<endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
