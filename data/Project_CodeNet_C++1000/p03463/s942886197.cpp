#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << - 1 << endl;}
void unhap() {cout << ":(" << endl;}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if ((b - a - 1) % 2 == 1) cout << "Alice";
  else cout << "Borys";
  cout << endl;
}