#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  a.push_back(x);
  
  sort(a.begin(), a.end(),greater<int>());
  
  int ans = a[0]-a[1];
  REP(i,n){
    ans = gcd(ans,(a[i]-a[i+1]));
  }
  cout << ans << endl;           
              
}