# include <vector>
# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 5e5 + 10;
const int mod = 1e9 + 7;

int n, a[M], b[M];
vector <int> vec;
ll cnt[30];

int main() {
  std :: ios :: sync_with_stdio(false); 
  std :: cin.tie(0); 
  std :: cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++ i) cin >> a[i];
  for (int i = 1; i <= n; ++ i) cin >> b[i];
  
  for (int digits = 0; digits <= 28; ++ digits) {
    vec.clear(); 
    for (int i = 1; i <= n; ++ i) vec.push_back((b[i] & ((1 << (digits + 1)) - 1)));
    sort(vec.begin(), vec.end());
    for (int i = 1, A, pointa, pointb; i <= n; ++ i) {
      A = (a[i] & ((1 << (digits + 1)) - 1));
      // 2^d <= a[i] + b[i] < 2^(d+1)
      pointa = lower_bound(vec.begin(), vec.end(), (1 << digits) - A) - vec.begin();
      pointb = lower_bound(vec.begin(), vec.end(), (1 << (digits + 1)) - A) - vec.begin();
      cnt[digits] += pointb - pointa;
      // 2^(d+1) + 2^d <= a[i] + b[i] < 2^(d+2)
      pointa = lower_bound(vec.begin(), vec.end(), (1 << (digits + 1)) + (1 << digits) - A) - vec.begin();
      pointb = vec.end() - vec.begin();
      cnt[digits] += pointb - pointa;
    }
  }
  int ans = 0;
  for (int i = 0; i <= 29; ++ i)
    if(cnt[i] & 1) ans |= (1 << i);
  cout << ans << endl;
  return 0;
}


