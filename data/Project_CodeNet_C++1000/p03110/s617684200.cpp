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
  ll n = 0;
  cin >> n;
  double res = 0;
  for(int i = 0;i < n;i++){
    double in;
    string t;
    cin >> in >> t;
    if(t[0] == 'J')res += in;
    else res += in * 380000;
  }
  cout << fixed << setprecision(20) << res << endl;
}

