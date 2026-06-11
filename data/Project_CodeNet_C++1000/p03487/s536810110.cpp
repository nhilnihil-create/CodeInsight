#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(100001);
  
  REP(i,n){
    int b;
    cin >> b;
    if(b > 100000) ans++;
    else a[b]++;
  }
  
  REP(i,100001){
    if(a[i] != 0){
      if(a[i] != i){
        if(a[i] > i) ans += a[i]-i;
        else ans += a[i];
      }
    }
  }
  
  cout << ans << endl;

}