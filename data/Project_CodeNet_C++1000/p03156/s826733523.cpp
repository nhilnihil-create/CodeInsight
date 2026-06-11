#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <iostream>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;
 
using ll = long long;
int p[100];
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  rep(i, n) cin >> p[i];
  sort(p, p+n);
  int i = 0;
  int mn = 0;
  int mi = 0;
  int mx = 0;
  while(p[i]<= a && i < n){
    i++;
    mn++;
  }
  while(p[i]<= b && i < n) {
    i++;
    mi++;
  }
  mx = n - i; 
  cout << min(mn, min(mi, mx)) << endl;
}
