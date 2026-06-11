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
  ll a,b,c;
  cin >> a >> b >> c;
  cout << min({abs(a - b) + abs(b - c),abs(b - a) + abs(a - c),abs(a - c) + abs(c - b)}) << endl;
}