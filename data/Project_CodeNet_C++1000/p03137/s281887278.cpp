#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;
typedef pair<int, int> P; 

int main() {
  int n,m,ans = 0;
  cin >> n >> m;
  vector<int> x(m);
  vector<int> a(m-1);
  
  REP(i,m){
    cin >> x[i];
  }
  sort(x.begin(),x.end(),greater<int>());
  REP(i,m-1){
    a[i] = x[i] - x[i+1];
  }
  sort(a.begin(),a.end());  
  
  if(m > n){
    REP(i,m-n){
      ans += a[i];
    }
    cout << ans << endl;
  }
  else{
    cout << 0 << endl;
  }
  
}
