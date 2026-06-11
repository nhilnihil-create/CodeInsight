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
  vector<ll> a(87);
  a[0] = 2;
  a[1] = 1;
  for(int i = 2;i <= 86;i++)a[i] = a[i - 1] + a[i - 2];
  cout << a[n] << endl;
}