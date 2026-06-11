#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  rep(i,10){
    c = a*c - b;
    cout << c << endl;
  }
}