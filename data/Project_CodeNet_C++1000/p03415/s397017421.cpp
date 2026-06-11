#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  char a[10];
  rep(i,9){
    cin >> a[i];
  }
  cout << a[0] << a[4] << a[8];
}