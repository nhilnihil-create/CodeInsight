#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int m = 0, s = 0, l;
  REP(i,n) {
    cin >> l;
    s += l;
    m = max(m,l);
  }
  
  cout << (m < s - m ? "Yes" : "No") << endl;

}
