#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r;cin>>r;
  string a="AGC";
  if(r<2800)a="ARC";
  if(r<1200)a="ABC";
  cout << a << endl;
}