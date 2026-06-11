#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll A, B;
  scanf("%lld %lld", &A, &B);

  if ((A * B) % 2 == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
