    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a,b,c,d,e,f;
      cin >> a;
      b = a % 10;
      c = a / 10;
      d = c % 10;
      e = c / 10;
      f = e % 10;
      cout << b + d + f << endl;
    }