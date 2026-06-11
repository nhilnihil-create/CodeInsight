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
  ll n,k;
  cin >> n >> k;
  if(n % k == 0)cout << 0 << endl;
  else cout << 1 << endl;
}