    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a=0,b=0,c=0;
      cin >> a >> b ;
      c=( 1.0-(a+b)/2.0 + (a+b)/2 )*((a+b)%2) + (a+b)/2.0;
      cout << c << endl;
    }