#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  cout << (m * 1900 + (n - m) * 100) * pow(2,m);
}