#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
#include <numeric>
typedef long long ll;
using namespace std;

int main(void){
  int x, y, z, k, i, j;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z), d(x*y), e(min(k,x*y)*z);

  for(i=0;i<x;i++){
    cin >> a[i];
    a[i] *= -1LL;
  }
  for(i=0;i<y;i++){
    cin >> b[i];
    b[i] *= -1LL;
  }
  for(i=0;i<z;i++){
    cin >> c[i];
    c[i] *= -1LL;
  }

  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      d[i*y+j] = a[i] + b[j];
    }
  }
  sort(d.begin(),d.end());
  sort(c.begin(),c.end());

  for(i=0;i<min(k,x*y);i++){
    for(j=0;j<z;j++){
      e[i*z+j] = d[i] + c[j];
    }
  }

  sort(e.begin(),e.end());

  for(i=0;i<k;i++){
    cout << e[i] * -1LL << endl;
  }

  return 0;
}
