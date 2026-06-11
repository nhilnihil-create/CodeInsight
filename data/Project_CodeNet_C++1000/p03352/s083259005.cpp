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
  ll x;
  cin >> x;
  ll res = 0;
  for(int i = 1;i <= 40;i++){
    for(int j = 2;j <= 10;j++){
      if(pow(i,j) <= x){
        res = max(res,(ll)pow(i,j));
      }
    }
  }
  cout << res << endl;
}