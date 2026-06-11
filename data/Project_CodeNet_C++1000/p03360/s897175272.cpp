#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c;
  cin >> k;
  ll ans = a + b + c + max(a,max(b,c))*pow(2, k) - max(a,max(b,c));
  print(ans);

}
