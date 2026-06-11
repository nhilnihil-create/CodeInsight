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
  int r;
  cin >> r;
  if (r < 1200) cout << "ABC" << endl;
  else if (r < 2800) cout << "ARC" << endl;
  else cout << "AGC" << endl;
}