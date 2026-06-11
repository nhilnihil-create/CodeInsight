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
  ull n, m;
  cin >> n >> m;
  
  vector<pair<ull, ull>> drinks;
  
  while (n--) {
    ull amount, cost;
    cin >> cost >> amount;
    
    drinks.pb(mp(cost, amount));
  }
  
  ull total = 0;
  
  sort(drinks.begin(), drinks.end());
  
  for (int i = 0; i < drinks.size() && m > 0; ++i) {
    total += drinks.at(i).first * min(drinks.at(i).second, m);
    
    m -= min(drinks.at(i).second, m);
  }
  
  cout << total << endl;

  return 0;
}