#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  double ave = 0;
  rep(i, n) {
    cin >> a[i];
    ave += a[i];
  }
  ave /= n;
  int ans = 0;
  double minv = INF;
  rep(i, n) {
    double diff = abs(ave - a[i]);
    if(minv > diff) {
      minv = diff;
      ans = i;
    }
  }
  cout << ans << endl;
  
}