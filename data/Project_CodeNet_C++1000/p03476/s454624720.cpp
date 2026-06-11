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
  vector<bool> prime(100101,true);
  prime[1] = false;
  for(int i = 2; i*i <= 100100; i++) {
    if (!prime[i]) continue;
    for(int j = i*2; j <= 100100; j += i) {
      prime[j] = false;
    }
  }
  vector<int> a(100100,0);
  rep(i,3,100001) {
    if (!prime[i]) continue;
    if (prime[(i + 1)/2]) a[i] = 1;
  }
  rep(i,0,100001) {
    a[i+1] += a[i];
  }
  int q;
  cin >> q;
  rep(i,0,q) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l-1] << "\n";
  }
  return 0;
}