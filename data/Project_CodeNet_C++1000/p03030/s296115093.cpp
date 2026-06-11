#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  vector<tuple<string, int, int>> a(n);
  string s;
  int p;
  REP(i,n) {
    cin >> s >> p;
    a[i] = make_tuple(s, -p, i+1);
  }
  
  sort(a.begin(), a.end());
                      
  REP(i,n) {
    cout << get<2>(a[i]) << endl;
  }
}