#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int x;
  cin >> x;
  
  int s1 = (x % 200) / 100;
  int s2 = (x % 20) / 10;
  int s3 =  x % 2;
  
  cout << s1 + s2 + s3;
}