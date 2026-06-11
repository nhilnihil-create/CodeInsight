#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  vi a;
  vi b;
  
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    
    a.pb(k);
  }
  
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    
    b.pb(k);
  }
  
  int res = 0;
  for (int intersect = 0; intersect < n; ++intersect) {
    int candies = 0;
    
    for (int i_a = 0; i_a <= intersect; ++i_a) {
      candies += a.at(i_a);
    }  
    
    for (int i_b = intersect ; i_b < n; ++i_b) {
      candies += b.at(i_b);
    }
    
    res = max(res, candies);
  }
  
  cout << res << endl;
  return 0;
}