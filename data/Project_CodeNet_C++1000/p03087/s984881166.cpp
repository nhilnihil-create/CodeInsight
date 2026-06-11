#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,q;
  string s;
  cin >> n >> q >> s;
  vector<int> a(n+1);
  REP(i,n+1){
    if(i != 0){
      if(s[i-1] == 'A' && s[i] == 'C'){
        a[i]++;
        
      }
      a[i] += a[i-1];
    }
  }
  
  REP(i,q){
    int l,r;
    cin >> l >> r;
    cout << a[r-1]-a[l-1] << endl;
  }
  
  
}
