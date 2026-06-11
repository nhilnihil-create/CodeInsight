#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  int n, k;
  cin >> n >> k;
  if (n % k == 0) cout << 0 << endl;
  else cout << 1 << endl;
}