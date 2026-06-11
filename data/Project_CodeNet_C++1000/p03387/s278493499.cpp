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
  vi va;
  
  int a, b, c;
  cin >> a >> b >> c;
  
  int d = max(a,max(b, c));
  
  int x = 0;
  
  if ((3*d % 2) == ((a+b+c) % 2)) {
    x = d;
  } else {
    x = d+1;
  }
  
  cout << (3*x-(a+b+c))/2;
  
  return 0;
}