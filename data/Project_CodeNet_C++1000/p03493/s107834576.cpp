#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int s;
  cin >> s;
  int a = (s / 100);
  int s1 = s % 100;
  int b = (s1 / 10);
  int s2 = s1 % 10;
  cout << a + b + s2 << endl;
}