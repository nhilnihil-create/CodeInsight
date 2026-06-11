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
  ll res = 0;
  if(a + b >= c){
    res = c + b;
  }
  else{
    res = a + b + b + 1;
  }
  cout << res << endl;
}