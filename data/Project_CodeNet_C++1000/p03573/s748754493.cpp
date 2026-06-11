#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
ll llmax = LLONG_MAX;
vll d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}
void sortll(vll &a) {sort(a.begin(), a.end());}
void sortc(string &a) {sort(a.begin(), a.end());}
void sorts(vs &a) {sort(a.begin(), a.end());}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == b) cout << c << endl;
  else if (b == c) cout << a << endl;
  else cout << b << endl;
}