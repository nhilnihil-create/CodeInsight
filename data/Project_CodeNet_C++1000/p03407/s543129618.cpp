#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
vi d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b >= c) Yes();
  else No();
}