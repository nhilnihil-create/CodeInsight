#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, sum = 0;
  cin >> n;
  
  vector<int> an(n+2);
  rep(i, n) {
    cin >> an[i+1];
    sum += abs(an[i+1] - an[i]);
  }
  sum += abs(an[n]);
  
  vector<int> bn(n);
  rep(i, n) {
    int s;
    s = sum 
      - abs(an[i] - an[i+1]) 
      - abs(an[i+1] - an[i+2])
      + abs(an[i] - an[i+2]);
    cout << s << endl;
  }
  
}
