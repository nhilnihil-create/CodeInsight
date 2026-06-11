#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  int sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    int cnt = 0;
    int ans = 0;
    while(ans <= d) {
      cnt++;
      ans = a*cnt+1;
    }
    sum += cnt;
  }
  int ret = sum  + x;
  
  cout << ret << endl;
  return 0;
}
    