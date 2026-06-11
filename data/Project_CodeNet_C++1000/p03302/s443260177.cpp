#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b;
  cin>>a>>b;
  if(a + b == 15) {
    cout << "+" << endl;
  } else if(a * b == 15) {
    cout << "*" << endl;
  } else {
    cout << "x" << endl;
  }

  return 0;
}
