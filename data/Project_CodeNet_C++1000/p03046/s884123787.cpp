#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int m,k;
  cin >> m >> k;
  if(1<<m <= k){
    cout << -1 << endl;
  }
  else if(m==0){
    printf("0 0\n");
  }
  else if(m==1){
    if(k==0) printf("0 0 1 1\n");
    else printf("-1\n");
  }
  else {
    int mm = 1<<m;
    rep(i,mm) if(i!=k) printf("%d ",i);
    printf("%d ",k);
    rep(i,mm) {
      int ii = mm - 1 - i;
      if(ii!=k) printf("%d ",ii);
    }
    printf("%d\n",k);
  }
}
