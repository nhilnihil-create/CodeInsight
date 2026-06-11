#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,c,d,e,A,B,C,D,E;
  cin >> a >> b >> c >> d >> e;
  
  A = a % 10; B = b % 10;
  C = c % 10; D = d % 10; E = e % 10;
  int x[] = {a,b,c,d,e};
  int y[] = {A,B,C,D,E};
  int mi = 130, t;
  for(int i = 0; i < 5; i++) {
    if(y[i] != 0 & mi > y[i]) {
      mi = y[i];
      t = i;
    }
  }
  int sum = 0;
  for(int i = 0; i < 5; i++) {
    if(i == t || y[i] == 0) sum += x[i];
    else sum += x[i] + (10-y[i]);
  }
  cout << sum << endl; 
}