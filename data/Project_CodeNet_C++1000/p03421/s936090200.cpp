    /**
     *    author:  tourist
     *    created: 26.11.2019 03:48:15       
    **/
    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n, a, b;
      cin >> n >> a >> b;
      if (a * 1LL * b < n || a + b - 1 > n) {
        cout << -1 << '\n';
        return 0;
      }
      vector<int> c(a, 1);
      c[0] = b;
      int ptr = 1;
      for (int i = a + b - 1; i < n; i++) {
        if (c[ptr] == b) {
          ++ptr;
        }
        ++c[ptr];
      }
      ptr = 0;
      for (int x : c) {
        for (int i = 0; i < x; i++) cout << ptr + x - i << " ";
        ptr += x;
      }
      return 0;
    }