#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int a1 = s[0] - '0';
  vector<int> a(3);
  REP(i,3) a[i] = s[i+1] - '0';
  
  int b;
  
  BREP(is,3){
    int sum = a1;
    REP(i,3){
      if((is>>i) & 1) sum += a[i];
      else sum -= a[i];
    }
    if(sum == 7) b = is;
  }
  
  cout << a1;
  REP(i,3){
    if((b>>i) & 1) cout << '+';
    else cout << '-';
    cout << a[i];
  }
  
  cout << "=7" << endl;
    

              
}