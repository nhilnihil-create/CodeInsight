    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a=0,b1=0,b2=0,b3=0;
      cin >> a ;
      b1=a/100;
      b2=(a%100)/10;
      b3=(a%100)%10;
      cout << b1+b2+b3 << endl;
    }