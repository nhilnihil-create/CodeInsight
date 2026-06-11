#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
    int b = a%999/100;
    int c = a%999%100/10;
    int d = a%999%10;
  if (a <= 999) cout << "ABC"<<endl;
  else cout << "ABD"<<endl;
}