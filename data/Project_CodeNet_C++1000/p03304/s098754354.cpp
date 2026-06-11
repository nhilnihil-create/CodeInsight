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
  double n,m,d;
  cin >> n >> m >> d;
  double res = 0;
  if(d == 0){
    res = double(1 / n);
    res *= m - 1;
  }
  else{
    res = double((2 * n - 2 * d) / (n * n));
    res *= m - 1;
  }
  cout << fixed << setprecision(10) << res << endl;
  return 0;
}