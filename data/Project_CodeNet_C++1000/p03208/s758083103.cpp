#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 1000000000;
int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  sort(h.begin(), h.end());
  int hmin = INF;
  rep(i, n - k + 1){
    int tmp = h[i+k-1] - h[i];
    hmin = min(hmin, tmp);
  }
  cout << hmin << endl;
}