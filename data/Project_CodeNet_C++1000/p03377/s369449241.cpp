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
  ll a,b,x;
  cin >> a >> b >> x;
  if(x >= a && a + b >= x)cout << "YES" << endl;
  else cout << "NO" << endl;
}