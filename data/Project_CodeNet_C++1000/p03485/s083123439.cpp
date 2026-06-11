    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a = 0 , b = 0, pass = 0;
      int ans = 0;
      cin >> a >> b;
      pass = (a + b) % 2;
      ans = (a + b) / 2;
      cout << ans + pass;
    }