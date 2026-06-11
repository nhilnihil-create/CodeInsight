#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int res = 0;
  int cnt = 1;
  rep(i,n-1) {
    if (a[i] == a[i+1]) cnt++;
    else res += cnt / 2, cnt = 1;
  }
  res += cnt / 2;
  cout << res << endl;
  return 0;
} 