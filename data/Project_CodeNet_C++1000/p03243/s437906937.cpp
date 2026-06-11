#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
  int n;
  cin >> n;
  if ( n %111 == 0) cout << n << endl;
  else cout <<n + (111-n%111) << endl;
  }