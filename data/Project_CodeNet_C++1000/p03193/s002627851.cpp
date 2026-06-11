#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, h, w;
  cin >> n >> h >> w;
  int ans = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (a >= h && b >= w) ans++;
  }
  cout << ans << endl;
}