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
  int n, m;
  cin >> n >> m;

  int f1[31] = {0};

  int k1;
  cin >> k1;
  for (int i = 0; i < k1; ++i) {
    int k;
    cin >> k;
    f1[k] = 1;
  }

  for (int i = 0; i < n-1; ++i) {
    int kt;
    cin >> kt;

    int fx[31] = {0};
    for (int j = 0; j < kt; ++j) {
      int a;
      cin >> a;
      fx[a] = 1;
    }

    for (int i = 0; i < 31; ++i) {
      f1[i] = (f1[i] & fx[i]);
    }
  }

  int count = 0;
  for (int i = 0; i < 31; ++i) {
    if (f1[i]) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
