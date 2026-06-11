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
  ll a,b,c,n;
  cin >> a >> b >> c >> n;
  ll res = 0;
  for(int i = 0;i <= a;i++){
    for(int j = 0;j <= b;j++){
      for(int k = 0;k <= c;k++){
        if(i * 500 + j * 100 + k * 50 == n)res++;
      }
    }
  }
  cout << res << endl;
}
