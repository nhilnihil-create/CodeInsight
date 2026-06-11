#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];
//平方根　= sqrt


bool check(string s);

int main() {
  string s;
  cin >> s;

  if (check(s)) {
    cout << "AC" << endl;
  }
  else {
    cout << "WA" << endl; 
  }
  return 0;
}

  bool check(string s){
    if (s[0] != 'A') return false;
    int c=0;
    // ３文字目からCがあるかしらべる
    for (int i=2;i<s.size()-1;i++) {
      if (s[i]=='C') {
        c++;
      }
    }

    if (c != 1) return false;

    int upper =0;
    for (int i=0;i<s.size(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        upper++;
      }
    }
    if (upper != 2) return false;
    return true;
  }
