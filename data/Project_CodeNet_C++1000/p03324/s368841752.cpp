#include <bits/stdc++.h>
using namespace std;
int d, n;
int main() {
   cin >> d >> n;
   if (d==2 && n==100) {cout << 1010000; return 0;}
   cout << (n!=100 ? n*pow(100, d) : 101*pow(100,d));  
}