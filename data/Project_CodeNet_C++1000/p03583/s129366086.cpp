#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  ll N;
  cin >> N;

  for(ll h = 1;h <= 3500;h++){
    for(ll n = 1;n <= 3500;n++){
      ll den = 4*n*h - N*(h + n);
      ll num = N * h * n;

      if(den > 0 && num % den == 0){
        ll w = num / den;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
}