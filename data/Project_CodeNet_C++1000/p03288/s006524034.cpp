#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll n; cin >> n;
  if(n < 1200){
    cout << "ABC";
  }
  else if(n < 2800){
    cout << "ARC";
  }
  else{
    cout << "AGC";
  }
}