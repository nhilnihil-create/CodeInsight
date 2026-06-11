#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, a, s1 = 0, s2 = 0;
  cin >> n;
  priority_queue<int> v;
  rep(i, n) {
    cin >> a;
    v.push(a);
  }
  rep(i, n) {
    if(i%2 == 0) {
      s1 += v.top();
    } else {
      s2 += v.top();
    }
    v.pop();
  }
  cout << s1 - s2 << endl;
}

