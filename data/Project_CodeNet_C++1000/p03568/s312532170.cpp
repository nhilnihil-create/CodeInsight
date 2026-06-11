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
  
  int a, b;
  a = b = 1;
  
  while (n--) {
    int k;
    cin >> k;
    
    a *= 3;
    if (k % 2 == 0) {
      b *= 2;
    }
  }
  
  cout << a-b << endl;
  return 0;
}