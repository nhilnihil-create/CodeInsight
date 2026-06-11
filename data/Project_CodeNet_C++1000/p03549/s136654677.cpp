#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n,m;
  cin >> n >> m;
  cout << (1900*m+100*(n-m))*pow(2,m) << endl;
}

