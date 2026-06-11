// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef tuple<ll, ll, ll> P;

/*
10 + 1
20 + 5 -> 10 
i = 0
t = 25
j = 1
c = 1, s = 10 ,f = 10

*/
int main() {
  int n; cin >> n;
  n--;
  vector<P> A;
  loop(i,0,n) {
    int a, b, c; cin >> a >> b >> c;
    A.emplace_back(a, b, c);
  }
  vector<ll> ans;
  for (int i=n-1; i>=0; i--) {
    ll t = get<1>(A[i]) + get<0>(A[i]);
    for (int j=i+1;j<n; j++) {
      ll c, s, f; tie(c, s, f) = A[j];
      if (t <= s) t = s + c;
      else {
        while (t > s) s += f;
        t = s + c;
      }
    }
    ans.push_back(t);
  }
  reverse(ans.begin(), ans.end());
  for (auto &&a: ans) cout << a << endl;
  cout << 0 << endl;
  return 0;
}
