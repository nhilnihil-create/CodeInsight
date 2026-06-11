#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  
  int place;
  double temp = 600;
  for(int i=1; i<=n; i++) {
    int x;
    double y;
    cin >> x;
    y = abs(a-(t-x*0.006));
    if(temp > y) { 
      temp = y;
      place = i;
    }
  }
  cout << place << endl;
  return 0;
}