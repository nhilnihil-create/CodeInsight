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
  int a, b;
  cin >> a >> b;
  
  if (b == 100) {
    b++;
  }
  cout << b;
  
  for (int i = 0; i < a; ++i) {
    cout << "00";
  }
  
  cout << endl;
  
  return 0;
}