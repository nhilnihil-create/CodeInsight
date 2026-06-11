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
  ll k = 0;
  for(int i = 1;i <= 11111;i++){
    ll now = i * 5 + 1;
    bool pri = true;
    for(int j = 2;j <= sqrt(now);j++){
      if(now % j == 0)pri = false;
    }
    if(k < n - 1 && pri)cout << now << " ",k++;
    else if(pri){
      cout << now << endl;
      return 0;
    }
  }
}