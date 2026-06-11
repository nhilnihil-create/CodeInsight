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
  ll n;
  cin >> n;
  
  int count = 0;
  
  while (n--) {
    ll k;
    cin >> k;
    
    while (!(k & 1)) {
      k >>= 1;
      count++;
    }
  }
  
  cout << count << endl;
  return 0;
}
