#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  int kyori;
  string kekka = "No";
  
  cin >> a >> b >> c >> kyori;
  
  if(abs(c - a) <= kyori) kekka = "Yes"; // 直接
  if(abs(c - b) <= kyori && abs(b - a) <= kyori) kekka = "Yes"; // 間接
  
  cout << kekka;
}
