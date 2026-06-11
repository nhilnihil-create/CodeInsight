#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int X;
  cin >> X;

  vector<int> v;
  v.push_back(1);
  for (int i = 2; i*i <= X; i++) {
    int b = i, p = 2;
    do {
      v.push_back(pow(b, p));
      p++;
    } while (pow(b, p) <= X);
  }

  sort(v.begin(),v.end());
  cout << v.back() << endl;
  return 0;
}
