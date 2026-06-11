#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n;
  ll x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());

  int c = 0;
  rep(i,n) {
    if (x >= a[i]){
      c++;
      x -= a[i];
    } else {
      break;
    }
  }

  if (x != 0 && c == n) c--;
  
  cout << max(c,0) << endl;

  return 0;
}
