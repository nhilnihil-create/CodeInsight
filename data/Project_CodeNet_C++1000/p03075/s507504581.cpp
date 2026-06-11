#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const string YES = "Yay!";
const string NO = ":(";

int main() {
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  ll c;
  cin >> c;
  ll d;
  cin >> d;
  ll e;
  cin >> e;
  ll k;
  cin >> k;
  cout << (e-a <= k ? YES : NO) << endl;
  return 0;
}
