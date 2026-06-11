#include<bits/stdc++.h>
using namespace std;

vector<string> ss;
int n;

bool works(int a, int b) {
  bool ans = true;
  for(int i=0;i<n;i++) {
    for(int j=i;j<n;j++) {
      int x1 = (i + a) % n;
      int y1 = (j + b) % n;
      int x2 = (j + a) % n;
      int y2 = (i + b) % n;
      ans = ans && (ss[x1][y1] == ss[x2][y2]);
    }
  }

  return ans;
}

int main() {
  cin >> n;
  ss.resize(n);
  for(int i=0;i<n;i++) {
    cin >> ss[i];
  }

  long long ans = n * works(0, 0);
  for(int i=1;i<n;i++) {
    bool x = works(i, 0);
    ans += (n - i) * x;

    x = works(0, i);
    ans += (n - i) * x;
  }

  cout << ans << endl;
}
