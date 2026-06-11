#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  if(n % 2 == 0)cout << n * n / 4 << endl;
  else cout << (n / 2) * (n / 2 + 1) << endl;
}