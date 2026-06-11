#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int s1000;
  int s100;
  int s10;
  int s1;
  cin >> N;
  s1000 = N / 1000;
  s100 = (N - 1000 * s1000) / 100;
  s10 = (N - 1000 * s1000 - 100 * s100) / 10;
  s1 = (N - 1000 * s1000 - 100 * s100 - 10 * s10);
  if (s1 == s10 && s1 == s100){
  cout << "Yes";
  }
  else if (s10 == s100 && s10 == s1000){
  cout << "Yes";
  }else{
    cout << "No";
}
}