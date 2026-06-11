#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<bool> prime(101,true);
  prime[1] = false;
  for(int i = 2; i*i <= 100; i++) {
    if (!prime[i]) continue;
    for(int j = i*2; j <= 100; j += i) {
      prime[j] = false;
    }
  }
  vector<int> div(100,0);
  int n;
  cin >> n;
  if (n <= 9) {
    cout << 0 << endl;
    return 0;
  }
  rep(i,2,n+1) {
    if (!prime[i]) continue;
    int p = i;
    while(n/p != 0) {
      div[i] += n/p;
      p *= i;
    }
  }
  int cnt2 = 0,cnt4 = 0,cnt14 = 0,cnt24 = 0,cnt74 = 0;
  rep(i,2,100) {
    if (div[i] >= 74) cnt74++;
    if (div[i] >= 24) cnt24++;
    if (div[i] >= 14) cnt14++;
    if (div[i] >= 4) cnt4++;
    if (div[i] >= 2) cnt2++;
  }
  int ans = 0;
  ans += cnt74;
  ans += cnt24*(cnt2-1);
  ans += cnt14*(cnt4-1);
  ans += ((cnt4*(cnt4-1))/2) * (cnt2-2);
  cout << ans << endl;
  return 0;
}
