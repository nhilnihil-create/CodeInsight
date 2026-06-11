    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a;
      int b;
      int c;
      cin >> a;
      b = a/100;
      a = a%100;
      c = a/10;
      a = a%10;
      cout << a+b+c << endl;
    }