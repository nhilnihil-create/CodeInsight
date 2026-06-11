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
  ll d,n;
  cin >> d >> n;
  ll count = 0;
  ll i = 0;
  while(1){
    i++;
    ll k = 0;
    ll copy = i;
    while(copy % 100 == 0){
      k++;
      copy /= 100;
    }
    if(k == d)count++;
    if(count == n){
      cout << i << endl;
      return 0;
    }
  }
}

