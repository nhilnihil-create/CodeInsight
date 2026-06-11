#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
int main() {
  double N;
  cin >> N;
  double a = 360/N;
  double b = 180-a;
  double ans = b*N;
  cout << ans << endl;
}