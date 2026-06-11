#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll D;
  scanf("%lld", &D);

  switch (D) {
    case 25:
      cout << "Christmas" << endl;
      break;
    case 24:
      cout << "Christmas Eve" << endl;
      break;
    case 23:
      cout << "Christmas Eve Eve" << endl;
      break;
    case 22:
      cout << "Christmas Eve Eve Eve" << endl;
      break;
  }
}
