#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

#define MAX 200001

int main()
{
  int n;
  int a[MAX], b[MAX];
  int ans = 0;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  for(int i = 0; i < 29; i++){
    int amod[MAX], bmod[MAX];
    int c = 0;

    for(int j = 0; j < n; j++){
      amod[j] = a[j] % (2<<i);
      bmod[j] = b[j] % (2<<i);
    }

    sort(amod, amod + n);
    sort(bmod, bmod + n);

    for(int j = 0; j < n; j++){
      c += lower_bound(bmod, bmod+n, 2*(1<<i) - amod[j]) - 
            lower_bound(bmod, bmod+n, (1<<i) - amod[j]);
      c += lower_bound(bmod, bmod+n, 4*(1<<i) - amod[j]) - 
            lower_bound(bmod, bmod+n, 3*(1<<i) - amod[j]);
    }

    if(c % 2){
      ans |= (1<<i);
    }
  }
  
  cout << ans << endl;

  return 0;
}
